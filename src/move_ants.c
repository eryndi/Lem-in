/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:01:48 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/10 20:46:33 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	print_ants(t_lemin *data)
{
	int i;
	int token;

	i = 0;
	token = 0;
	while (i < data->num_ants)
	{
		if (data->ants[i]->print)
		{
			if (token == 0)
			{
				ft_dprintf(1, "L%d-%s", data->ants[i]->id,
						data->ants[i]->start->name);
				token = 1;
			}
			else
				ft_dprintf(1, " L%d-%s", data->ants[i]->id,
						data->ants[i]->start->name);
		}
		i++;
	}
	ft_putchar('\n');
}

static int	find_not_finished(t_lemin *data)
{
	int i;

	i = data->num_ants - 1;
	while (i >= 0)
	{
		if (!data->ants[i]->finished)
			return (1);
		i--;
	}
	return (0);
}

static void	move_forward(t_lemin *data, int i)
{
	data->ants[i]->start->free = true;
	data->ants[i]->start = data->ants[i]->start->next;
	if (!data->ants[i]->start->is_end)
	{
		data->ants[i]->start->free = false;
	}
	else
		data->ants[i]->finished = true;
	return ;
}

void		move_ants(t_lemin *data)
{
	int	i;

	while (find_not_finished(data))
	{
		i = 0;
		while (i < data->num_ants)
		{
			if (data->ants[i]->finished)
				data->ants[i]->print = false;
			else if (!data->ants[i]->finished && !data->ants[i]->print)
			{
				if (data->ants[i]->start->free)
				{
					data->ants[i]->print = true;
					data->ants[i]->start->free = false;
				}
			}
			else if (!data->ants[i]->finished && data->ants[i]->print)
				move_forward(data, i);
			i++;
		}
		print_ants(data);
	}
	return ;
}

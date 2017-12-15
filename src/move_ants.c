/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_ants.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 17:01:48 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/15 12:12:21 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	print_ants(t_lemin *data)
{
	int		i;
	int		token;
	char	color_code[9];

	i = 0;
	token = 0;
	ft_bzero(color_code, 8);
	ft_dprintf(1, " here ");
	while (i < data->num_ants)
	{
		if (data->ants[i]->print)
		{
			color_that_ant(data->ants[i]->id, color_code);
			if (token == 0)
			{
				ft_dprintf(1, "%sL%d-%s%s", color_code, data->ants[i]->id,
						data->ants[i]->start->name, PF_EOC);
				token = 1;
			}
			else
			{
				ft_dprintf(1, " %sL%d-%s%s", color_code, data->ants[i]->id,
						data->ants[i]->start->name, PF_EOC);
			}
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
		data->ants[i]->start->free = false;
	else
		data->ants[i]->finished = true;
	return ;
}

static void	enter_map(t_lemin *data, int i)
{
	if (data->ants[i]->start->free)
	{
		data->ants[i]->print = true;
		data->ants[i]->start->free = false;
		if (data->ants[i]->start->is_end)
		{
			data->ants[i]->finished = true;
			data->ants[i]->start->free = true;
		}
	}
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
				enter_map(data, i);
			else if (!data->ants[i]->finished && data->ants[i]->print)
				move_forward(data, i);
			i++;
		}
		print_ants(data);
	}
	return ;
}

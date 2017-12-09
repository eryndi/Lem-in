/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:28:25 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/09 19:59:23 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
// remember to set variable nb_ants in t_room to 0 in init!
static int	count_paths(t_room *start_room)
{
	int	i;

	i = 0;
	while (start_room->next_start[i])
		i++;
	return (i);
}

static void	ant_distribution(t_lemin *data, t_room *start_room)
{
	int		counter;
	int		i;
	t_room	*tmp;

	ft_putstr("Hello from ant_distribution\n");
	counter = 0;
	while (counter <= data->num_ants)
	{
		i = 0;
		while (start_room->next_start[i])
		{
			if (start_room->next_start[i + 1])
			{
				if (start_room->next_start[i]->len <= start_room->next_start[i + 1]->len)
				{
					tmp = start_room->next_start[i];
					break ;
				}
			}
			else
				tmp = start_room->next_start[i];
			i++;
		}
		tmp->nb_ants++;
		tmp->len++;
		counter++;
	}
	return ;
}

void		remove_extra_paths(t_lemin *data, t_room *start_room)
{
	int		i;

	ft_putstr("Hello from remove extra paths\n");
	i = 0;
	while (start_room->next_start[i])
		i++;
	while (data->num_ants < i)
	{
		i--;
		start_room->next_start[i] = NULL;
	}
	i = (count_paths(start_room) - 1);
	while (i > 0)
	{
		if (start_room->next_start[i]->len > (start_room->next_start[i - 1]->len + data->num_ants))
			start_room->next_start[i] = NULL;
		i--;
	}
	ant_distribution(data, start_room);
	return ;
}

void	decide_paths(t_lemin *data)
{
	t_room	*start_room;
	t_room	*tmp;
	
	ft_putstr("Hello from decide paths\n");
	tmp = data->rooms;
	while (tmp)
	{
		if (tmp->is_start)
		{
			start_room = tmp;
			break ;
		}
		tmp = tmp->parse_next;
	}
	remove_extra_paths(data, start_room);
	return ;
}

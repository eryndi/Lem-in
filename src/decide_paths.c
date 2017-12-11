/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:28:25 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/11 20:05:02 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		count_paths(t_room *start_room)
{
	int	i;

	i = 0;
	while (start_room->next_start[i])
		i++;
	return (i);
}

static t_room	*find_shortest_path(t_lemin *data, t_room *start_room)
{
	int		i;
	t_room	*shortest;

	i = 0;
	while (start_room->next_start[i])
	{
		if (start_room->next_start[i + 1])
		{
			if (start_room->next_start[i]->len <=
					start_room->next_start[i + 1]->len)
			{
				shortest = start_room->next_start[i];
				break ;
			}
		}
		else
			shortest = start_room->next_start[i];
		i++;
	}
	return (shortest);
}

static void		ant_distribution(t_lemin *data, t_room *start_room)
{
	int		counter;
	int		i;
	t_room	*shortest;

	counter = 0;
	while (counter <= data->num_ants)
	{
		shortest = find_shortest_path(data, start_room);
		shortest->nb_ants++;
		shortest->len++;
		counter++;
	}
	return ;
}

void			remove_extra_paths(t_lemin *data, t_room *start_room)
{
	int		i;

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
		if (start_room->next_start[i]->len >
				(start_room->next_start[i - 1]->len + data->num_ants))
			start_room->next_start[i] = NULL;
		i--;
	}
	ant_distribution(data, start_room);
	return ;
}

t_room			*decide_paths(t_lemin *data)
{
	t_room	*start_room;
	t_room	*tmp;

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
	return (start_room);
}

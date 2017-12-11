/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 16:28:56 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/11 13:53:08 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		get_number_paths(t_room *start_room)
{
	int i;

	i = 0;
	while (start_room->next_start[i])
		i++;
	return (i);
}

static t_ant	*init_ant(int i)
{
	t_ant	*ant;

	ant = (t_ant *)malloc(sizeof(t_ant));
	ant->id = i;
	ant->print = false;
	ant->finished = false;
	ant->start = NULL;
	return (ant);
}

static t_room	*find_start_room(t_lemin *data)
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
	return (start_room);
}

void			assign_ants(t_lemin *data)
{
	int		i;
	int		j;
	int		nb_paths;
	t_room	*start_room;

	start_room = find_start_room(data);
	data->ants = (t_ant **)malloc(sizeof(t_ant *) * data->num_ants + 1);
	data->ants[data->num_ants] = NULL;
	nb_paths = get_number_paths(start_room);
	i = 0;
	while (i < data->num_ants)
	{
		j = 0;
		while (j < nb_paths)
		{
			if (start_room->next_start[j]->nb_ants > 0 && i < data->num_ants)
			{
				data->ants[i] = init_ant(i + 1);
				data->ants[i]->start = start_room->next_start[j];
				start_room->next_start[j]->nb_ants--;
				i++;
			}
			j++;
		}
	}
	i = 0;
}

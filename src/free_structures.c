/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_structures.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 19:39:27 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/11 20:05:15 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static void	free_ants(t_lemin *data)
{
	int i;

	i = 0;
	while (i < data->num_ants)
	{
		free(data->ants[i]);
		i++;
	}
	free(data->ants);
	return ;
}

static void	free_rooms(t_room *room)
{
	t_tube	*tmp_tube;
	t_room	*tmp_room;

	while (room)
	{
		free(room->name);
		free(room->coord_x);
		free(room->coord_y);
		while (room->tube)
		{
			tmp_tube = room->tube;
			free(room->tube->name);
			room->tube = room->tube->next;
			free(tmp_tube);
		}
		free(room->next_start);
		free(room->connections);
		tmp_room = room;
		room = room->parse_next;
		free(tmp_room);
	}
	return ;
}

void		free_structures(t_lemin *data)
{
	free_rooms(data->rooms);
	free_ants(data);
	return ;
}

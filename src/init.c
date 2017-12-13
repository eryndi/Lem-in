/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:41:31 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/13 16:13:51 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			init_room(t_room *room, char **room_x_y)
{
	room->name = room_x_y[0];
	room->is_start = false;
	room->is_end = false;
	room->coord_x = room_x_y[1];
	room->coord_y = room_x_y[2];
	room->free = 1;
	room->next = NULL;
	room->next_start = NULL;
	room->connections = NULL;
	room->is_enqueued = false;
	room->is_dequeued = false;
	room->len = -1;
	room->is_path = -1;
	room->parse_next = NULL;
	room->tube = NULL;
	room->nb_ants = 0;
	return (1);
}

void		init_start_end(t_lemin *data, t_room *new_room)
{
	if (new_room->is_start)
		data->s_room = new_room;
	if (new_room->is_end)
		data->e_room = new_room;
}

int			init(t_lemin *data)
{
	data->ants = NULL;
	data->rooms = NULL;
	data->path_number = 0;
	data->num_ants = -1;
	data->start = 0;
	data->end = 0;
	data->lines = NULL;
	data->s_room = NULL;
	data->e_room = NULL;
	return (1);
}

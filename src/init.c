/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:41:31 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/10 20:22:45 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			init_room(t_room *room)
{
	room->name = NULL;
	room->is_start = false;
	room->is_end = false;
	room->coord_x = NULL;
	room->coord_y = NULL;
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

int			init(t_lemin *data)
{
	data->ants = NULL;
	data->rooms = NULL;
	data->num_ants = -1;
	data->start = 0;
	data->end = 0;
	data->lines = NULL;
	return (1);
}

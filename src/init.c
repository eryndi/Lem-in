/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:41:31 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/04 17:42:40 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			init_room(t_room *room)
{
	room->name = NULL;
	room->is_start = 0;
	room->is_end = 0;
	room->coord_x = NULL;
	room->coord_y = NULL;
	room->occupied = 0;
	room->next = NULL;
	room->connections = NULL;
	room->is_checked = 0;
	room->is_path = -1;
	room->parse_next = NULL;
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
	ft_dprintf(1, "#init\n");////////
	return (1);
}

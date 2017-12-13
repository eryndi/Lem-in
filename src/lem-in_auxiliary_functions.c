/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in_auxiliary_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:53:22 by dwald             #+#    #+#             */
/*   Updated: 2017/12/13 16:13:55 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	clear_map(t_room *room)
{
	while(room != NULL)
	{
		if (room->next != NULL)
			room->is_enqueued = false;
		room->is_dequeued = false;
		room = room->parse_next;
	}
}

t_room	*get_end_room(t_room *room)
{
//	ft_dprintf(1, PF_CYAN"Hello from get end room\n"PF_EOC);
	
	while (room != NULL)
	{
		if (room->is_end == true)
			return (room);
		room = room->parse_next;
	}
	ft_dprintf(1, PF_RED"Error, END room not found\n"PF_EOC);
	return (NULL);
}

int		number_of_rooms(t_room *rooms)
{
	int		len;
	t_room	*end;
//	ft_dprintf(1, PF_CYAN"Hello from number of rooms\n"PF_EOC);
	
	len = 0;
	end = rooms;
	while (end != NULL)
	{
		end = end->parse_next;
		len++;
	}
	return (len);
}

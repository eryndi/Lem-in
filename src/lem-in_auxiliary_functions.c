/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in_auxiliary_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:53:22 by dwald             #+#    #+#             */
/*   Updated: 2017/12/13 15:53:28 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

t_room	*mark_path(t_room *room, int path_number)
{
//	ft_dprintf(1, PF_CYAN"Hello from mark path\n"PF_EOC);
	ft_dprintf(1, PF_CYAN"path_number = %i\n"PF_EOC, path_number);
	while (room->next != NULL)
	{
		ft_dprintf(1, PF_MAGENTA"path room->name = %s\n"PF_EOC, room->name);
		room->is_path = path_number;
		room = room->next;
	}
	return (room);
}

void    clear_pile(t_room **pile, int *start, int *n, int *i)
{
	ft_bzero(pile, *i + 1);
	*start = 0;
	*n = -1;
	*i = 0;
	return ;
}

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

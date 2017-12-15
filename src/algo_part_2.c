/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_part_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:53:22 by dwald             #+#    #+#             */
/*   Updated: 2017/12/15 11:24:52 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	mark_path(t_room *room, int path_number)
{
	unsigned	int	length;
	t_room			*start_next;

	length = 0;
	start_next = room;
	while (room != NULL)
	{
		room->is_path = path_number;
		room = room->next;
		length++;
	}
	start_next->len = length;
	return ;
}

void	clear_pile(t_room **pile, int *start, int *n, int *i)
{
	ft_bzero(pile, *i + 1);
	*start = 0;
	*n = -1;
	*i = 0;
	return ;
}

void	clear_map(t_room *room)
{
	while (room != NULL)
	{
		if (room->next != NULL)
			room->is_enqueued = false;
		room->is_dequeued = false;
		room = room->parse_next;
	}
}

int		number_of_rooms(t_room *rooms)
{
	int		len;
	t_room	*end;

	len = 0;
	end = rooms;
	while (end != NULL)
	{
		end = end->parse_next;
		len++;
	}
	return (len);
}

void	allocate_memory(t_room *start, int paths)
{
	start->next_start = (t_room**)malloc(sizeof(t_room) * paths + 1);
	if (start->next_start == NULL)
		ft_protect_malloc();
	while (paths)
		start->next_start[paths--] = NULL;
	return ;
}

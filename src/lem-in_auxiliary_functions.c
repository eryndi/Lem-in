/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in_auxiliary_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:53:22 by dwald             #+#    #+#             */
/*   Updated: 2017/12/11 16:59:29 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	prepare_structure(t_lemin *data)
{
	int	i;
//	ft_dprintf(1, PF_CYAN"Hello from prepare_structure\n"PF_EOC);

	i = 0;
	while (i < 6)
	{
		data->rooms[i].next = NULL;
		data->rooms[i].is_path = -1;
//		data->rooms[i].is_start = 0;
//		data->rooms[i].is_end = 0;
//		data->rooms[i].connections = NULL;
		i++;
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
	ft_dprintf(1, PF_RED"Hello seg fault END room not found\n"PF_EOC);
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

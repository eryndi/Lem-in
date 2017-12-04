/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 10:20:03 by dwald             #+#    #+#             */
/*   Updated: 2017/12/04 16:00:06 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Dijsktra's algorithm finds the minimum distance from node START to all nodes 
** So in return you get the minimum distance tree from node START.
*/

/*
✅   Find room END
❌    Verify if room is available at the map (room->path == -1) then look at every room connection you have:
		if (room->path == -1 &&  room->checked == false)
		while (room->connections->name != NULL);
❌   2.1.    If true and it’s not START nor END => Set room as checked
room->is_checked = (room->is_start == false && room->is_end == false) ? true : false; 
❌    2.2.    If room connection is not a START nor END then set the next pointer of 
the connection room to my room. This way the room which precedes 
my room has a pointer set to my room and we start to set-up a path towards END backwards.
❌    If ((room->connection->is_end == false && room->connection->is_start == false) && room->connection->is_path == -1)) // room is not already in another path
            room->connection->next == room->name;
*/
static	t_room	*get_end_room(t_lemin *data)
{
	t_room	*end;

	end = data->rooms;
	while (end->parse_next != NULL)
	{
		if (end->is_end == true)
			return (end);
		end = end->parse_next;
	}
	return (NULL);
}

void	algo(t_lemin *data)
{
	t_room *ptr;

	ptr = get_end_room(data);
	ptr = ptr.connections;
	while (ptr.is_path == -1 && ptr.connections != NULL)
	{
		if (ptr.is_start == true)
			ft_dprintf(1, "Hello\n");	
	}
}	

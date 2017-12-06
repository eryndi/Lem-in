/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 10:20:03 by dwald             #+#    #+#             */
/*   Updated: 2017/12/06 16:00:35 by dwald            ###   ########.fr       */
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

static	void	bfs_algo(t_lemin *data, t_room *ptr, int i)
{
	int		n;

	n = 0;
// put all end->connecttions pointer to next on end address (not only one as below
	while (ptr->is_start == false && ptr->is_end == false) //till we arrive at the beggining of the list
	{
		while ((ptr->connections != NULL)
		&& (ptr->is_path == -1 && || ptr->connections[n] != NULL))
		{
			ft_dprintf(1, PF_RED"Hello\n"PF_EOC);
			if (ptr->connections[i]->is_start == true)
			{
				ptr->is_path = 1;
				ft_dprintf(1, "NEXT is STRAT\n");
				//launch function to mark all the ptr->next as path == 1;
				//and stock this node to *next_start[i]
			}
			i++;
		}
		if (ptr->connections != NULL && ptr->connections[i] == NULL)
		{
			ptr->connections[i + 1]->next = ptr;
			return (bfs_algo(ptr->connection[n], 0);
		}
		if (ptr->connections == NULL)
			return (bfs_algo(data, ptr->next->connection[i + 1], i + 1);
			//one level up to search the neighbor if he does exist
	}
	if (ptr->is_end == true)
		ft_dprintf(1, "NEXT is the END, start was not found\n");
	return ;		
}

void		algo_launcher(t_lemin *data, int i)
{
	ft_dprintf(1, PF_CYAN"Hello from algo_launcher\n"PF_EOC);
	t_room *ptr;
	t_room *end;

	end = get_end_room(data);
	ptr = end->connections[i];
	ft_dprintf(1, PF_CYAN"name of end room %s\n"PF_EOC, end->name);
	ft_dprintf(1, PF_CYAN"room[1]  address %p\n"PF_EOC, &data->rooms[1]);
	ft_dprintf(1, PF_CYAN"end->connections %p\n"PF_EOC, end->connections[i]);
	ft_dprintf(1, PF_CYAN"end->connections %s\n"PF_EOC, (end->connections[i]->name));
// put all end->connecttions pointer to next on end address (not only one as below
	ptr->next = end;
	bfs_algo(data, end->connection[i], i);
}

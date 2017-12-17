/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_part_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 10:20:03 by dwald             #+#    #+#             */
/*   Updated: 2017/12/17 17:10:30 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** BFS algorithm finds the minimum distance from node END to all nodes.
** In return we get the minimum distance tree from node END to START.
** End node (vertex/room) is visited when it is put on pile (enqueued) and
** marked as enqueued. Its connections (aka adjacent nodes) are put on pile
** until there is no adjacent node left in the address book (room->connections)
** of the visited node. At this moment, the visited node is marked as deuqueued.
** Next visited node is the first unvisited node on the pile according to the
** FIFO principle.
** If, during analysis (visiting), a START node is identified on the pile,
** the node and all the following nodes creating a path from START to END are
** marked as is_path = true. The path itself dynamically is stored in the
** t_room->next pointer.
** The pile is renewed ignoring nodes which already participate in a stored path
*/

static	t_room	*store_path(t_lemin *data, t_room *start, t_room *vertex)
{
	int		paths;

	paths = 0;
	start->next = vertex;
	while (start->connections[paths] != NULL)
		paths++;
	if (start->next_start == NULL)
		allocate_memory(start, paths);
	if (data->path_number < paths)
	{
		start->next_start[data->path_number] = start->next;
		mark_path(data, start->next, data->path_number);
		clear_map(data->rooms);
		if (start->next == data->e_room)
			start_end_path(data);
		start->next = NULL;
		data->path_number++;
		return (data->e_room);
	}
	else
		return_error("ERROR more paths than possible\n");
	exit(1);
}

static	int		get_room_to_put_on_pile(t_room *vertex, int n)
{
	if (vertex->connections[n] != NULL
	&& vertex->connections[n]->is_start == false
	&& vertex->connections[n]->is_end == false
	&& vertex->connections[n]->is_enqueued == false
	&& vertex->connections[n]->is_dequeued == false
	&& vertex->connections[n]->is_path == -1)
	{
		vertex->connections[n]->next = vertex;
		vertex->connections[n]->is_enqueued = true;
		return (1);
	}
	else
		return (0);
}

static	int		dequeue_vertex(int start, int i, t_room **pile, t_room **vertex)
{
	while (start < i && pile[start]->is_dequeued == true)
		start++;
	if (start == i)
		return (-1);
	else if (pile[start]->is_dequeued == false)
	{
		*vertex = pile[start];
		(*vertex)->is_dequeued = true;
	}
	return (start);
}

static	void	bfs_algo(t_lemin *data, t_room *vertex, int length, int i)
{
	t_room	*pile[length + 1];
	int		n;
	int		start;

	clear_pile(pile, &start, &n, &i);
	pile[i++] = vertex;
	while (i < length)
	{
		if (get_room_to_put_on_pile(vertex, ++n) == 1)
			pile[i++] = vertex->connections[n];
		else if (vertex->connections[n] == NULL)
		{
			if ((start = dequeue_vertex(start, i, pile, &vertex)) == -1)
			{
				if (data->s_room->next_start == NULL)
					return_error("ERROR no path found\n");
				return ;
			}
			else
				n = -1;
		}
		else if ((vertex->connections[n]->is_start == true) &&
		((vertex = store_path(data, vertex->connections[n], vertex)) != NULL))
			clear_pile(pile, &start, &n, &i);
	}
}

void			algo_launcher(t_lemin *data)
{
	int		length;
	int		i;

	data->e_room->next = NULL;
	data->e_room->is_enqueued = false;
	length = number_of_rooms(data->rooms);
	i = length + 1;
	bfs_algo(data, data->e_room, length, i);
}

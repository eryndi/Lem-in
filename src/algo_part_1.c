/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_part_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 10:20:03 by dwald             #+#    #+#             */
/*   Updated: 2017/12/14 15:41:35 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** BFS algorithm finds the minimum distance from node START to all nodes
** So in return you get the minimum distance tree from node START.
*/

static	t_room	*store_path(t_lemin *data, t_room *start, t_room *vertex)
{
	int		paths;
//	ft_dprintf(1, PF_CYAN"Hello from store_path\n"PF_EOC);

	paths = 0;
	start->next = vertex;
	while (start->connections[paths] != NULL)
		paths++;
	if (start->next_start == NULL)
		allocate_memory(start, paths);
//ft_dprintf(1, PF_CYAN"path_number = %i paths = %i\n"PF_EOC, data->path_number, paths);
	if (data->path_number < paths)
	{
		start->next_start[data->path_number] = start->next;
		mark_path(start->next, data->path_number);
		clear_map(data->rooms);
		if (start->next == data->e_room)
			start_end_path(data);
		start->next = NULL;
		data->path_number++;
		return (data->e_room);
	}
	else
		ft_dprintf(1, "Error in number of START paths\n");
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
//	ft_dprintf(1, PF_CYAN"Hello dequeue vertex\n"PF_EOC);
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

//	ft_dprintf(1, PF_CYAN"Hello from bfs_algo\n"PF_EOC);
	clear_pile(pile, &start, &n, &i);
	n = -1;
	pile[i++] = vertex;
	while (i < length)
	{
		if (get_room_to_put_on_pile(vertex, ++n) == 1)
			pile[i++] = vertex->connections[n];
		else if (vertex->connections[n] == NULL)
		{
			if ((start = dequeue_vertex(start, i, pile, &vertex)) == -1)
				return ;
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

//	ft_dprintf(1, PF_CYAN"Hello from algo_launcher\n"PF_EOC);
	data->e_room->next = NULL;
	data->e_room->is_enqueued = false;
	length = number_of_rooms(data->rooms);
	i = length + 1;
	bfs_algo(data, data->e_room, length, i);
}
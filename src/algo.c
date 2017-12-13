/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 10:20:03 by dwald             #+#    #+#             */
/*   Updated: 2017/12/13 14:18:44 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** BFS algorithm finds the minimum distance from node START to all nodes 
** So in return you get the minimum distance tree from node START.
*/

static	t_room	*mark_path(t_room *room, int path_number)
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
	
static	t_room	*store_path(t_lemin *data, t_room *start)
{
	int		paths;
	int		i;
	t_room	*end;

	paths = 0;
	i = 0;
	while (start->connections[paths] != NULL)
		paths++;
	if (start->next_start == NULL)
	{
		start->next_start = (t_room**)malloc(sizeof(t_room)*paths + 1);
		if (start->next_start == NULL)
			ft_protect_malloc();
		while (i != paths)
			start->next_start[i++] = NULL;
	}
ft_dprintf(1, PF_CYAN"path_number = %i paths = %i\n"PF_EOC, data->path_number, paths);
	if (data->path_number < paths)
	{
		start->next_start[data->path_number] = start->next;
		end = mark_path(start->next, data->path_number);
		clear_map(data->rooms);
		start->next = NULL;
		data->path_number++;
		return (end);
//ft_dprintf(1, PF_CYAN"strat->next_strat[%i] = %s path_number = %i paths = %i\n"PF_EOC, i, start->next_start[i]->name, path_number, paths);
	}
	else
		ft_dprintf(1, "Error in number of START paths\n");
	exit (1);
}

static	int		get_room_on_pile(t_room *vertex, int n)
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

static	void	bfs_algo(t_lemin *data, t_room *vertex, int len, int i)
{
	t_room	*pile[len + 1];
	int		n;
	int		start;

//	ft_dprintf(1, PF_CYAN"Hello from bfs_algo\n"PF_EOC);
	n = 0;
	start = 0;
	ft_bzero(pile, len + 1);
	while (i < len)
	{
		if (get_room_on_pile(vertex, n) == 1)
			pile[i++] = vertex->connections[n];
		else if (vertex->connections[n] == NULL)
		{
			while (start < i && pile[start]->is_dequeued == true)
				start++;
			if (start == i)
				return ;
			else if (pile[start]->is_dequeued == false)
			{
					vertex = pile[start];
					vertex->is_dequeued = true;
					n = -1;
			}
		}
		else if (vertex->connections[n]->is_start == true)
		{
//			ft_dprintf(1, PF_RED"START\n"PF_EOC);
			vertex->connections[n]->next = vertex;
			vertex = store_path(data, vertex->connections[n]);
			ft_bzero(pile, len + 1);
//			vertex->connections[n]->next = vertex;
			start = 0;
			n = -1;
			i = 0;
		}
		n++;
	}
	return ;
}

void		algo_launcher(t_lemin *data)
{
//	ft_dprintf(1, PF_CYAN"Hello from algo_launcher\n"PF_EOC);
	t_room *end;
	int		len;
	int		i;

	i = 0;
	if ((end = get_end_room(data->rooms)) == NULL)
		exit (1);
	end->next = NULL;
	end->is_enqueued = true;
	len = number_of_rooms(data->rooms);
	bfs_algo(data, end, len, i);
}

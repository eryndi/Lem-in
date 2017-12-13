/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 10:20:03 by dwald             #+#    #+#             */
/*   Updated: 2017/12/13 16:56:13 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** BFS algorithm finds the minimum distance from node START to all nodes 
** So in return you get the minimum distance tree from node START.
*/

static	t_room	*store_path(t_lemin *data, t_room *start, t_room *vertex, int i)
{
	int		paths;
	t_room	*end;

	paths = 0;
	i = 0;
	start->next = vertex;
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
	}
	else
		ft_dprintf(1, "Error in number of START paths\n");
	exit (1);
}

static	int		get_room_to_put_on_pile(t_room *vertex, int n)
{
//ft_dprintf(1, PF_MAGENTA"vertex->connections[%d]\n"PF_EOC, n);
//	if (vertex->connections[n] != NULL) 
//ft_dprintf(1, PF_MAGENTA"vertex->connections[%d] = %s\n"PF_EOC, n, vertex->connections[n]->name);
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

static	void	bfs_algo(t_lemin *data, t_room *vertex, int len, int i)
{
	t_room	*pile[len + 1];
	int		n;
	int		start;

//	ft_dprintf(1, PF_CYAN"Hello from bfs_algo\n"PF_EOC);
	clear_pile(pile, &start, &n, &i);
	n = 0;
	while (i < len)
	{
		if (get_room_to_put_on_pile(vertex, n) == 1)
		{
			pile[i++] = vertex->connections[n];
			//ft_dprintf(1, "pile[%d] = %p\n", i-1, pile[i - 1]);
		}
		else if (vertex->connections[n] == NULL)
		{
			if ((start = dequeue_vertex(start, i, pile, &vertex)) == -1)
				return ;
			else
				n = -1;
		}
		else if ((vertex->connections[n]->is_start == true) && 
		((vertex = store_path(data, vertex->connections[n], vertex, i))!= NULL))
			clear_pile(pile, &start, &n, &i);
		n++;
	}
}

void		algo_launcher(t_lemin *data)
{
//	ft_dprintf(1, PF_CYAN"Hello from algo_launcher\n"PF_EOC);
	t_room *end;
	int		len;
	int		i;

	if ((end = get_end_room(data->rooms)) == NULL)
		exit (1);
	end->next = NULL;
	end->is_enqueued = true;
	len = number_of_rooms(data->rooms);
	i = len + 1;
	bfs_algo(data, end, len, i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 10:20:03 by dwald             #+#    #+#             */
/*   Updated: 2017/12/08 17:42:26 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** BFS algorithm finds the minimum distance from node START to all nodes 
** So in return you get the minimum distance tree from node START.
*/

static	t_room	*get_end_room(t_lemin *data)
{
	t_room	*end;
	
//	ft_dprintf(1, PF_CYAN"Hello from get end room\n"PF_EOC);
	
	end = data->rooms;
	while (end != NULL)
	{
		if (end->is_end == true)
			return (end);
		end = end->parse_next;
	}
	ft_dprintf(1, PF_RED"Helloi seg fault END room not found\n"PF_EOC);
	return (NULL);
}

static	int		number_of_rooms(t_room *rooms)
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
	
static	int	store_path(t_room *start, int path_number)
{
	int		paths;
	int		i;

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
//	ft_dprintf(1, PF_CYAN"path_number = %i paths = %i\n"PF_EOC, path_number, paths);
	if (path_number < paths)
	{
		start->next_start[path_number] = start->next;
		start->next = NULL;
	for (int i = 0; path_number == paths - 1 && i < paths; i++)
ft_dprintf(1, PF_CYAN"strat->next_strat[%i] = %s path_number = %i paths = %i\n"PF_EOC, i, start->next_start[i]->name, path_number, paths);
		return (path_number);
	}
	else
	{
		ft_dprintf(1, "Error in number of START paths\n");
		exit (1);
	}
}

static	void	bfs_algo(t_room *vertex, int len)
{
	t_room	*pile[len + 1];
	int		n;
	int		i;
	int		start;
	int		path_number;

//	ft_dprintf(1, PF_CYAN"Hello from bfs_algo\n"PF_EOC);
	n = 0;
	i = 0;
	start = 0;
	path_number = -1;
	ft_bzero(pile, len + 1);
	vertex->is_enqueued = true;
//	ft_dprintf(1, PF_CYAN"vertex->name = %s\n"PF_EOC, vertex->name);
	while (i < len)
	{
		if (vertex->connections[n] != NULL 
		&& vertex->connections[n]->is_start == false
		&& vertex->connections[n]->is_end == false
		&& vertex->connections[n]->is_enqueued == false
		&& vertex->connections[n]->is_dequeued == false)
		{
			vertex->connections[n]->next = vertex;
			vertex->connections[n]->is_enqueued = true;
			pile[i] = vertex->connections[n];
//			ft_dprintf(1, PF_CYAN"pile[%d] = %s\n"PF_EOC, i, pile[i]->name);
			i++;
		}
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
			path_number = store_path(vertex->connections[n], path_number + 1);
		}
		n++;
	}
	return ;
}

void		algo_launcher(t_lemin *data, int i)
{
	ft_dprintf(1, PF_CYAN"Hello from algo_launcher\n"PF_EOC);
	t_room *end;
	int		len;

	end = get_end_room(data);
	end->next = NULL;
	len = number_of_rooms(data->rooms);
//	ft_dprintf(1, PF_RED"Hello\n"PF_EOC);
	bfs_algo(end, len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 10:20:03 by dwald             #+#    #+#             */
/*   Updated: 2017/12/06 18:56:54 by dwald            ###   ########.fr       */
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

	end = data->rooms;
	while (end->parse_next != NULL)
	{
		if (end->is_end == true)
			return (end);
		end = end->parse_next;
	}
	return (NULL);
}

static	void	store_path(t_room *vertex, t_room *strat)
{
		
}

static	void	bfs_algo(t_room *vertex, int i)
{
	int		n;

	n = 0;
	ft_dprintf(1, PF_CYAN"Hello from bfs_algo\n"PF_EOC);
	if (vertex == NULL)
	{
		ft_dprintf(1, "Error\n");
		ft_dprintf(1, "next is the end, start was not found\n");
		exit (1);
	}
	vertex->connections[i]->next = vertex;
	vertex = vertex->connections[i];
	ft_dprintf(1, PF_CYAN"vertex room name: %s\n"PF_EOC, vertex->name);
	if (vertex->connections == NULL)
	{
		ft_dprintf(1, "moving to neighbour vertex\n");
		return (bfs_algo(vertex->next, i + 1));//level up to search neighbour
	}
	if (vertex->is_start == true)
	{
		ft_dprintf(1, "start was found directly\n");
	}
	else if (vertex->is_start == false)//till we arrive at the beggining of the list
	{
	//	ft_dprintf(1, PF_RED"Hello\n"PF_EOC);
		while (vertex->connections[n] != NULL && vertex->is_path == -1)
		{
			if ( vertex->connections[n] == vertex->next)
			{
				n++;
				break;
			}
ft_dprintf(1, "hello checking vertex %s%s%s connections n = %d\n", PF_RED, vertex->name, PF_EOC, n);
ft_dprintf(1, "room connection name:%s%s%s\n", PF_CYAN, vertex->connections[n]->name, PF_EOC);
			if (vertex->connections[n]->is_start == true)
			{
				vertex->is_path = 1;
				ft_dprintf(1, "next is strat\n");
				ft_dprintf(1, PF_CYAN"room: %s\n"PF_EOC, vertex->name);
				store_path(vertex, vertex);
				break;
				//launch function to mark all the ptr->next as path == 1;
				//and stock this node to *next_start[i]
			}
			n++;
		}
		if (vertex->connections[n] == NULL && vertex->next->connections[i+1] != NULL)
		{
			ft_dprintf(1, PF_RED"Recursive to upper level\n"PF_EOC);
			return (bfs_algo(vertex->next, i + 1));
		}
		if (vertex->connections[n] == NULL && vertex->next->connections[i+1] == NULL)
		{
			ft_dprintf(1, PF_GREEN"Recursive to lower level\n"PF_EOC);
			return (bfs_algo(vertex->connections[0], 0));
		}
	}
	return ;		
}

void		algo_launcher(t_lemin *data, int i)
{
	ft_dprintf(1, PF_CYAN"Hello from algo_launcher\n"PF_EOC);
	t_room *end;

	end = get_end_room(data);
	end->next = NULL;
//	ft_dprintf(1, PF_RED"Hello\n"PF_EOC);
	bfs_algo(end, i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_part_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 10:20:03 by dwald             #+#    #+#             */
/*   Updated: 2017/12/14 15:44:46 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** BFS algorithm finds the minimum distance from node START to all nodes
** So in return you get the minimum distance tree from node START.
*/

void	start_end_path(t_lemin *data)
{
	int		end_address;
	int		n;

	n = 0;
	while (data->e_room->connections[n] != NULL)
	{
		if (data->e_room->connections[n] == data->s_room)
		{
			end_address = n;
			break ;
		}
		n++;
	}
	while (data->e_room->connections[n] != NULL)
		n++;
	ft_swap_pointers((void**)&(data->e_room->connections[end_address]),
	(void**)&(data->e_room->connections[n - 1]));
	data->e_room->connections[n - 1] = NULL;
	return ;
}

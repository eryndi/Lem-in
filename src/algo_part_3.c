/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_part_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 10:20:03 by dwald             #+#    #+#             */
/*   Updated: 2017/12/14 15:52:15 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Start-end function acts when special case of path is found consisting only
** of strat and end room. To enable correct resume of algrithm the connection
** to strat from end address book of connections is removed. The path is,
** however, properly stored in room->next_start address book.
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

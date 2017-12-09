/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_connections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:44:23 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/08 17:48:55 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
//for each room
//	count list of tubes
//	malloc the room **connections for that size
//	for each element find the address of *room
//	put the address into **connections
//	end with NULL

static t_room	*add_address(t_lemin *data, t_room *current_room, int j)
{
	t_room	*search;
	t_tube	*tmp_tube;

	search = data->rooms;
	tmp_tube = current_room->tube;
	while (j != 0)
	{
		tmp_tube = tmp_tube->next;
		j--;
	}
	while (!ft_strequ(tmp_tube->name, search->name))
		search = search->parse_next;
	return (search);
}

static int		count_list(t_tube *tube)
{
	t_tube	*tmp;
	int		i;

	tmp = tube;
	i = 0;
	if (!tmp)
		return (0);
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

int				make_connections(t_lemin *data)
{
	t_room	*current_room;
	int		i;
	int		j;
ft_dprintf(1, PF_CYAN"Hello from make connections\n"PF_EOC);
	i = 0;
	current_room = data->rooms;
	while (current_room)
	{
		i = count_list(current_room->tube);
		current_room->connections = (t_room **)malloc(sizeof(t_room *) * i + 1);
		j = 0;
		while (j < i)
		{
			current_room->connections[j] = add_address(data, current_room, j);
			j++;
		}
//		ft_dprintf(1, "hello j = %d\n", j);
		current_room->connections[j] = NULL;
		current_room = current_room->parse_next;
	}
	return (1);
}

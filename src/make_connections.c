/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_connections.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:44:23 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/13 16:14:30 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

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
	t_room	*cur_room;
	int		i;
	int		j;

	i = 0;
	cur_room = data->rooms;
	while (cur_room)
	{
		i = count_list(cur_room->tube);
		if (!(cur_room->connections =
					(t_room **)malloc(sizeof(t_room *) * i + 1)))
			ft_protect_malloc();
		j = 0;
		while (j < i)
		{
			cur_room->connections[j] = add_address(data, cur_room, j);
			j++;
		}
		cur_room->connections[j] = NULL;
		cur_room = cur_room->parse_next;
	}
	return (1);
}

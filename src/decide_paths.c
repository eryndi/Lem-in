/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:28:25 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/08 18:06:53 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
// remember to set variable nb_ants in t_room to 0 in init!

void	distribute_ants(t_lemin *data, t_room *start_room)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (counter <= data->num_ants)
	{
		if (start_room->next_start[i]
		while (start_room->next_start[i]->len <
		start_room->next_start[i]->len++;
		start_room->next_start[i]->nb_ants++;
	}
}

void	remove_extra_paths(t_lemin *data, t_room *start_room)
{
	int		i;

	i = 0;
	while (start_room->next_start[i])
		i++;
	while (data->num_ants < i)
	{
		i--;
		start_room->next_start[i] = NULL;
	}
	while (i > 0)
	{
		if (start_room->next_start[i]->len > (start_room->next_start[i - 1]->len + data->num_ants))
			start_room->next_start[i] = NULL;
		i--;
	}
	distribute_ants(data, start_room);
	return ;
}

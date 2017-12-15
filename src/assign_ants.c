/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_ants.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 16:28:56 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/15 11:30:21 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static t_ant	*init_ant(int i)
{
	t_ant	*ant;

	if (!(ant = (t_ant *)malloc(sizeof(t_ant))))
		ft_protect_malloc();
	ant->id = i;
	ant->print = false;
	ant->finished = false;
	ant->start = NULL;
	return (ant);
}

void			assign_ants(t_lemin *data, t_room *start_room)
{
	int		i;
	int		j;

	if (!(data->ants = (t_ant **)malloc(sizeof(t_ant *) * data->num_ants + 1)))
		ft_protect_malloc();
	data->ants[data->num_ants] = NULL;
	i = 0;
	while (i < data->num_ants)
	{
		j = 0;
		while (j < data->path_number)
		{
			if (start_room->next_start[j]->nb_ants > 0 && i < data->num_ants)
			{
				data->ants[i] = init_ant(i + 1);
				data->ants[i]->start = start_room->next_start[j];
				start_room->next_start[j]->nb_ants--;
				i++;
			}
			j++;
		}
	}
}

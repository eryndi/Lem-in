/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decide_paths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/07 19:28:25 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/17 16:45:33 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int		replace_path_number(t_room *start_room)
{
	int i;

	i = 0;
	while (start_room->next_start[i])
		i++;
	return (i);
}

static t_room	*find_shortest_path(t_room *start_room)
{
	int		i;
	t_room	*shortest;

	i = 0;
	while (start_room->next_start[i])
	{
		if (start_room->next_start[i + 1] != NULL)
		{
			if (start_room->next_start[i]->len <=
					start_room->next_start[i + 1]->len)
			{
				shortest = start_room->next_start[i];
				break ;
			}
		}
		else
			shortest = start_room->next_start[i];
		i++;
	}
	return (shortest);
}

static void		ant_distribution(t_lemin *data, t_room *start_room)
{
	int		counter;
	t_room	*shortest;

	counter = 0;
	while (counter <= data->num_ants)
	{
		shortest = find_shortest_path(start_room);
		shortest->nb_ants = shortest->nb_ants + 1;
		shortest->len = shortest->len + 1;
		counter++;
	}
	return ;
}

void			decide_paths(t_lemin *data)
{
	int		i;

	i = 0;
	i = replace_path_number(data->s_room);
	while (data->num_ants < i)
	{
		i--;
		data->s_room->next_start[i] = NULL;
	}
	i = replace_path_number(data->s_room) - 1;
	while (i > 1)
	{
		if (data->s_room->next_start[i]->len >
				(data->s_room->next_start[i - 1]->len + data->num_ants))
			data->s_room->next_start[i] = NULL;
		i--;
	}
	data->path_number = replace_path_number(data->s_room);
	ant_distribution(data, data->s_room);
	return ;
}

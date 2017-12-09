/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in_auxiliary_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:53:22 by dwald             #+#    #+#             */
/*   Updated: 2017/12/06 17:48:16 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	prepare_structure(t_lemin *data)
{
	int	i;
	ft_dprintf(1, PF_CYAN"Hello from prepare_structure\n"PF_EOC);

	i = 0;
	while (i < 6)
	{
		data->rooms[i].next = NULL;
		data->rooms[i].is_path = -1;
//		data->rooms[i].is_start = 0;
//		data->rooms[i].is_end = 0;
//		data->rooms[i].connections = NULL;
		i++;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in_auxiliary_functions.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 13:53:22 by dwald             #+#    #+#             */
/*   Updated: 2017/12/04 15:34:40 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

void	prepare_structure(t_lemin *data)
{
	int	i;

	i = 0;
	while (i < 6)
	{
		data->rooms[i].next = NULL;
		data->rooms[i].is_path = -1;
		i++;
	}
}

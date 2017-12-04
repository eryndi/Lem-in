/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:41:31 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/04 16:14:48 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int			init(t_lemin *data)
{
	data->ants = NULL;
	data->rooms = NULL;
	data->num_ants = -1;
	data->start = 0;
	data->end = 0;
	data->lines = NULL;
	ft_dprintf(1, "#init\n");////////
	return (1);
}

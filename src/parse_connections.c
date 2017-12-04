/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_connections.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 18:20:14 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/04 18:33:08 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

int	parse_connections(t_lemin *data, char *line)
{
	char	*tmp;

	if (!data->start || !data->end)
	{
		ft_putstr("ERROR no start or end\n");
		return (0);
	}
	tmp = line;
	while (*tmp)
	{
		if (*tmp == 
		tmp
	}
}

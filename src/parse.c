/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:31:26 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/10 21:07:59 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

/*
** Check if char * is bigger than INTMAX
*/

static int	parse_ants(t_lemin *data)
{
	char	*line;
	char	*tmp;

	if (get_next_line(0, &line) != 1)
	{
		ft_putstr("ERROR reading line\n");
		return (0);
	}
	tmp = line;
	if (!*tmp)
	{
		ft_putstr("ERROR empty line\n");
		return (0);
	}
	while (*tmp)
	{
		if (!ft_isdigit(*tmp))
		{
			ft_putstr("ERROR number of ants not an int\n");
			return (0);
		}
		tmp++;
	}
	data->num_ants = ft_atoi(line);
	if (data->num_ants < 1)
	{
		ft_putstr("ERROR wrong number of ants\n");
		return (0);
	}
	ft_list_push_end(&data->lines, tmp);
	return (1);
}

int		parse(t_lemin *data)
{
	if (!parse_ants(data) || !parse_rooms(data))
		return (0);
	if (!make_connections(data))
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:31:26 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/04 21:47:24 by dhadley          ###   ########.fr       */
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
	if (!*line)
	{
		ft_putstr("ERROR empty line\n");
		return (0);
	}
	tmp = line;
	while (*line)
	{
		if (!ft_isdigit(*line))
		{
			ft_putstr("ERROR number of ants not an int\n");
			return (0);
		}
		line++;
	}
	data->num_ants = ft_atoi(tmp);
	if (data->num_ants < 1)
	{
		ft_putstr("ERROR wrong number of ants\n");
		return (0);
	}
	ft_list_push_end(&data->lines, tmp);
	ft_dprintf(1, "finished parsing ants, there are %d of them\n", data->num_ants); ////
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

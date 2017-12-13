/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:31:26 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/13 14:52:38 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	parse_ants(t_lemin *data)
{
	char	*line;
	char	*tmp;

	if (get_next_line(0, &line) != 1)
		return_error("ERROR reading line\n");
	tmp = line;
	if (!*tmp)
		return_error("ERROR empty line\n");
	while (*tmp)
	{
		if (!ft_isdigit(*tmp))
			return_error("ERROR number of ants not an int\n");
		tmp++;
	}
	tmp = line;
	data->num_ants = ft_atoi(line);
	if (data->num_ants < 1)
		return_error("ERROR wrong number of ants\n");
	ft_list_push_end(&data->lines, tmp);
	return (1);
}

int			parse(t_lemin *data)
{
	if (!parse_ants(data) || !parse_rooms(data))
		return_error("ERROR\n");
	if (!make_connections(data))
		return_error("ERROR\n");
	return (1);
}

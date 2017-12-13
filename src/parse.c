/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:31:26 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/13 16:52:27 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	count_digits(char *line)
{
	char	*tmp;
	int		i;

	i = 0;
	tmp = line;
	while (ft_isdigit(*tmp))
	{
		i++;
		tmp++;
	}
	if (i > 10)
		return_error("ERROR number of ants bigger than INT_MAX\n");
	return (i);
}

static void	check_int_max(char *line)
{
	int		i;
	char	*tmp;

	tmp = line;
	if ((i = count_digits(line)) == 10)
	{
		if (ft_strcmp(tmp, "2147483647") > 0)
			return_error("ERROR number of ants bigger than INT_MAX\n");
	}
	return ;
}

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
	check_int_max(tmp);
	data->num_ants = ft_atoi(line);
	if (data->num_ants < 1)
		return_error("ERROR wrong number of ants\n");
	ft_list_push_end(&data->lines, line);
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

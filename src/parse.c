/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 16:31:26 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/01 19:13:08 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Check if char * is bigger than INTMAX
*/

static int	parse_ants(t_lemin *data)
{
	char	*line;

	if (get_next_line(0, &line) != 1)
		return (0);
	if (!*line)
		return (0);
	tmp = line;
	while (*line)
	{
		if (!ft_isdigit(*line))
			return (0);
		line++;
	}
	data->num_ants = ft_atoi(tmp);
	if (data->num_ants < 1)
		return (0);
	data->lines = ft_lstnew(tmp, ft_strlen(tmp));
	free(tmp);
	return (1);
}

int		parse(t_lemin *data)
{
	if (!parse_ants(data))
		return (0);
}

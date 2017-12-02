/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:45:09 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/02 20:20:33 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	save_room(t_lemin *data, char **room_x_y)
{
	t_room	*room;
	int		i;

	i = 0;
	room = (t_room *)malloc(sizeof(t_room));
	room->name = room_x_y[0];
	room->coord_x = room_x_y[1];
	room->coord_y = room_x_y[2];
	if (data-
}

static int	check_room(t_lemin *data, char *line)
{
	int		i;
	char	*tmp;
	char	**room_x_y;

	tmp = line;
	while (*tmp)
	{
		if (*tmp == ' ')
			i++;
		tmp++;
	}
	if (i != 2)
		return (0);
	room_x_y = ft_strsplit(line, ' ');
	i = 0;
	while (room_x_y[i])
		i++;
	if (i != 3 || room_x_y[0][0] == '#' || room_x_y[0][0] == 'L')
		return (0);
	save_room(data, room_x_y);
}
// use a token to know if the previous significant line was a start or end
static int	check_command(t_lemin *data, char *line)
{
	if (line[1] == '#')
	{
		if (ft_strcmp(line, "##start"))
			return (1)
			//set_bool_start
			//return 1
		else if (ft_strcmp(line, "##end"))
			return (2);
			//set_bool_end
			//return 1
	}
	return (0);
}

int			parse_rooms(t_lemin *data)
{
	char	*line;
	t_room	*room;
	int		token;

	token = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (!*line || *line == ' ')
			return (0);
		if (line[0] == '#')
			tokem = check_command(data, line);
		else if (!ft_strchr(line, '-'))
			break; //finished parsing rooms
		check_room(data, line);
	}
	
}

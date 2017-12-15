/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:45:09 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/15 11:35:48 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	add_room(t_lemin *data, t_room *new_room, int i)
{
	t_room	*tmp;

	i = 0;
	while (new_room->coord_x[i])
	{
		if (!ft_isdigit(new_room->coord_x[i]))
			return_error("ERROR bad coordinated\n");
		i++;
	}
	i = 0;
	while (new_room->coord_y[i])
	{
		if (!ft_isdigit(new_room->coord_y[i]))
			return_error("ERROR bad coordinated\n");
		i++;
	}
	tmp = data->rooms;
	while (tmp->parse_next != NULL)
	{
		if (!ft_strcmp(tmp->name, new_room->name))
			return_error("ERROR double room\n");
		tmp = tmp->parse_next;
	}
	tmp->parse_next = new_room;
	return (1);
}

static int	fill_room(t_lemin *data, char **room_x_y, int *token)
{
	t_room	*new_room;
	int		i;

	i = 1;
	if (!(new_room = (t_room *)malloc(sizeof(t_room))))
		ft_protect_malloc();
	init_room(new_room, room_x_y);
	if (*token == 1 || *token == 3)
		new_room->is_start = 1;
	else if (*token == 2 || *token == 3)
		new_room->is_end = 1;
	*token = 0;
	if (data->rooms == NULL)
		data->rooms = new_room;
	else
		i = add_room(data, new_room, i);
	init_start_end(data, new_room);
	free(room_x_y);
	return (i);
}

static int	check_room(t_lemin *data, char *line, int *token)
{
	int		i;
	char	*tmp;
	char	**room_x_y;

	i = 0;
	tmp = line;
	while (*tmp)
	{
		if (*tmp == ' ')
			i++;
		tmp++;
	}
	if (i != 2)
		return_error("ERROR invalid room format\n");
	room_x_y = ft_strsplit(line, ' ');
	i = 0;
	while (room_x_y[i])
		i++;
	if (i != 3 || room_x_y[0][0] == '#' || room_x_y[0][0] == 'L')
		return_error("ERROR invalid room\n");
	if (fill_room(data, room_x_y, token))
		return (1);
	return (0);
}

static int	check_command(t_lemin *data, char *line, int *token)
{
	if (line[1] == '#')
	{
		if (!ft_strcmp(line, "##start"))
		{
			if (data->start)
				return_error("ERROR start already exists\n");
			data->start = true;
			*token = (*token == 2) ? 3 : 1;
			if (*token == 3)
				return_error("ERROR start is end\n");
			return (1);
		}
		else if (!ft_strcmp(line, "##end"))
		{
			if (data->end)
				return_error("ERROR end already exists\n");
			data->end = true;
			*token = (*token == 1) ? 3 : 2;
			if (*token == 3)
				return_error("ERROR start is end\n");
			return (1);
		}
	}
	return (1);
}

int			parse_rooms(t_lemin *data)
{
	char	*line;
	int		token;
	int		i;

	token = 0;
	while ((i = get_next_line(0, &line)) == 1)
	{
		if (!*line || *line == ' ')
			return_error("ERROR empty line\n");
		if (line[0] == '#')
			check_command(data, line, &token);
		else if (ft_strchr(line, '-'))
		{
			if (parse_tubes(data, line))
				return (1);
			return (0);
		}
		else if (!(i = check_room(data, line, &token)))
			return (0);
		ft_list_push_end(&data->lines, line);
	}
	if (!ft_strchr(line, '-'))
		return_error("ERROR no connections!\n");
	return (1);
}

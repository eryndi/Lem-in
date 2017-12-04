/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:45:09 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/04 14:46:28 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	add_room(t_lemin *data, t_room *new_room)
{
	t_room	*tmp;
	int		i;

	i = 0;
	while (new_room->coord_x[i])
	{
		if (!ft_isdigit(new_room->coord_x[i]))
			return (0);
		i++;
	}
	i = 0;
	while (new_room->coord_y[i])
	{
		if (!ft_isdigit(new_room->coord_y[i]))
			return (0);
		i++;
	}
	tmp = data->rooms;
	while (tmp->parse_next != NULL)
	{
		if (!ft_strcmp(tmp->name, new_room->name))
			return (0);
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
		return (0);
	new_room->name = room_x_y[0];
	new_room->coord_x = room_x_y[1];
	new_room->coord_y = room_x_y[2];
	new_room->parse_next == NULL;
	if (*token == 1 || *token == 3)
	{
		new_room->is_start = 1;
		data->start = 1;
	}
	else if (*token == 2 || *token == 3)
	{
		new_room->is_end = 1;
		data->end = 1;
	}
	*token = 0;
	if (data->rooms == NULL)
		data->rooms = new_room;
	else
		i = add_room(data, new_room);
	return (i);
}

static int	check_room(t_lemin *data, char *line, int *token)
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
				return (0);
			(*token >= 2) ? *token = 3 : *token = 1;
			return (1)
		}
		else if (!ft_strcmp(line, "##end"))
		{
			if (data->end)
				return (0);
			(*token == 1 || *token == 3) ? *token = 3 : *token = 2;
			return (1);
		}
	}
	return (1);
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
			check_command(data, line, &token); //if 0 ERROR
		else if (!ft_strchr(line, '-'))
			break; //finished parsing rooms
		else
			check_room(data, line, &token);
		ft_list_push_end(data->lines, line);
	}
	
}

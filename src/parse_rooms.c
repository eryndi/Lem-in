/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rooms.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/02 17:45:09 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/11 13:44:51 by dhadley          ###   ########.fr       */
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
		{
			ft_putstr("ERROR bad coordinated\n");
			return (0);
		}
		i++;
	}
	i = 0;
	while (new_room->coord_y[i])
	{
		if (!ft_isdigit(new_room->coord_y[i]))
		{
			ft_putstr("ERROR bad coordinated\n");
			return (0);
		}
		i++;
	}
	tmp = data->rooms;
	while (tmp->parse_next != NULL)
	{
		if (!ft_strcmp(tmp->name, new_room->name))
		{
			ft_putstr("ERROR double room\n");
			return (0);
		}
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
	init_room(new_room);
	new_room->name = room_x_y[0];
	new_room->coord_x = room_x_y[1];
	new_room->coord_y = room_x_y[2];
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
	{
		ft_putstr("ERROR invalid room format\n");
		return (0);
	}
	room_x_y = ft_strsplit(line, ' ');
	i = 0;
	while (room_x_y[i])
		i++;
	if (i != 3 || room_x_y[0][0] == '#' || room_x_y[0][0] == 'L')
	{
		ft_putstr("ERROR invalid room\n");
		return (0);
	}
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
			{
				ft_putstr("ERROR start already exists\n");
				return (0);
			}
			*token = (*token >= 2) ? 3 : 1;
			return (1);
		}
		else if (!ft_strcmp(line, "##end"))
		{
			if (data->end)
			{
				ft_putstr("ERROR end already exists\n");
				return (0);
			}
			*token = (*token == 1 || *token == 3) ? 3 : 2;
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
	int		i;
	
	i = 1;
	token = 0;
	while (get_next_line(0, &line) == 1)
	{
		if (!*line || *line == ' ')
		{
			ft_putstr("ERROR empty line\n");
			return (0);
		}
		if (line[0] == '#')
			check_command(data, line, &token); //if 0 ERROR
		else if (ft_strchr(line, '-'))
		{
			if (parse_tubes(data, line))
				return (1);
			return (0);
		}
		else
			i = check_room(data, line, &token);
		if (i == 0)
			return (0);
		ft_list_push_end(&data->lines, line);
	}
	if (!ft_strchr(line, '-'))
	{
		ft_putstr("ERROR no connections!\n");
		return (0);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tubes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:11:54 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/17 16:13:44 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

static int	check_double(t_room *room, char *name)
{
	t_tube	*tmp;
	t_tube	*new_tube;

	tmp = room->tube;
	if (tmp)
	{
		while (tmp->next)
		{
			if (ft_strequ(tmp->name, name))
				return (0);
			tmp = tmp->next;
		}
	}
	if (!(new_tube = (t_tube *)malloc(sizeof(t_tube))))
		ft_protect_malloc();
	new_tube->name = name;
	new_tube->next = NULL;
	if (tmp)
		tmp->next = new_tube;
	else
		room->tube = new_tube;
	return (1);
}

static int	add_tube(t_lemin *data, char *first, char *second)
{
	t_room	*tmp;

	tmp = data->rooms;
	while (!ft_strequ(first, tmp->name))
		tmp = tmp->parse_next;
	if (!check_double(tmp, second))
		return (0);
	tmp = data->rooms;
	while (!ft_strequ(second, tmp->name))
		tmp = tmp->parse_next;
	if (!check_double(tmp, first))
		return (0);
	return (1);
}

static int	check_exists(t_lemin *data, char *first, char *second)
{
	t_room	*tmp;
	int		i;

	i = 0;
	tmp = data->rooms;
	while (tmp)
	{
		if (ft_strequ(first, tmp->name))
			i++;
		if (ft_strequ(second, tmp->name))
			i++;
		tmp = tmp->parse_next;
	}
	if (i == 2)
		return (1);
	return (0);
}

static char	**check_line_tabs(t_lemin *data, char *line)
{
	char	*tmp;
	int		i;

	if (!data->start || !data->end)
		return_error("ERROR no start or end\n");
	i = 0;
	tmp = line;
	while (*tmp)
	{
		if (!ft_isprint(*tmp))
			return (NULL);
		if (*tmp == '-')
			i++;
		tmp++;
	}
	if (i != 1)
		return (NULL);
	return (ft_strsplit(line, '-'));
}

int			parse_tubes(t_lemin *data, char *line)
{
	char	**name_name;
	char	*new_line;

	if (!(name_name = check_line_tabs(data, line)))
		return_error("ERROR wrong connection format\n");
	if (!check_exists(data, name_name[0], name_name[1]) ||
			!add_tube(data, name_name[0], name_name[1]))
		return_error("ERROR room name doesnt exist\n");
	free(name_name);
	ft_list_push_end(&data->lines, line);
	while (get_next_line(0, &new_line) == 1)
	{
		if (!(new_line[0] == '#'))
		{
			if (!(name_name = check_line_tabs(data, new_line)))
				return_error("ERROR wrong connection format\n");
			if (!(check_exists(data, name_name[0], name_name[1])))
				return_error("ERROR tube name doesnt exist\n");
			if (!add_tube(data, name_name[0], name_name[1]))
				return_error("ERROR connection already exists\n");
			free(name_name);
		}
		ft_list_push_end(&data->lines, new_line);
	}
	return (1);
}

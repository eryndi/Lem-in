/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tubes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:11:54 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/10 21:03:28 by dhadley          ###   ########.fr       */
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
	new_tube = (t_tube *)malloc(sizeof(t_tube));
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

static char	**check_line_tabs(char *line)
{
	char	*tmp;
	int		i;

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
	char	*tmp;
	char	**name_name;

	if (!data->start || !data->end)
	{
		ft_putstr("ERROR no start or end\n");
		return (0);
	}
	if (!(name_name = check_line_tabs(line)))
	{
		ft_putstr("ERROR wrong connection format\n");
		return (0);
	}
	if (!check_exists(data, name_name[0], name_name[1]))
	{
		ft_putstr("ERROR tube name doesnt exist\n");
		return (0);
	}
	if (!add_tube(data, name_name[0], name_name[1]))
	{
		ft_putstr("ERROR connection already exists\n");
		return (0);
	}
	ft_list_push_end(&data->lines, line);
	while (get_next_line(0, &line) == 1)
	{
		if (!(line[0] == '#'))
		{
			if (!(name_name = check_line_tabs(line)))
			{
				ft_putstr("ERROR wrong connection format\n");
				return (0);
			}
			if (!(check_exists(data, name_name[0], name_name[1])))
			{
				ft_putstr("ERROR tube name doesnt exist\n");
				return (0);
			}
			if (!add_tube(data, name_name[0], name_name[1]))
			{
				ft_putstr("ERROR connection already exists\n");
				return (0);
			}
		}
		ft_list_push_end(&data->lines, line);
	}
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tubes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhadley <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 21:11:54 by dhadley           #+#    #+#             */
/*   Updated: 2017/12/05 17:32:54 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
//O check that the line is correct
//O	check that it has 1 '-'
//O	check that is has 2 tabs if split
//O for each tab check that the room exists
//O before adding the name, check that the name isnt already in the list
//O add the name of tab1 to the *tube to the tab[0]
//O do the opposite

static int	check_double(t_tube *tube, char *name)
{
	t_tube	*tmp;
	t_tube	*new_tube;

	tmp = tube;
	while (tmp)
	{
		if (ft_strequ(tmp->name, name))
			return (0);
		tmp = tmp->next;
	}
	tmp = tube;
	if (tmp)
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
	}
	new_tube = (t_tube *)malloc(sizeof(t_tube));
	new_tube->name = name;
	new_tube->next = NULL;
	tmp->next = new_tube;
	return (1);
}

static int	add_tube(t_lemin *data, char *first, char *second)
{
	t_room	*tmp;

	tmp = data->rooms;
	while (!ft_strequ(first, tmp->name))
		tmp = tmp->parse_next;
	if (!check_double(tmp->tube, first))
		return (0);
	tmp = data->rooms;
	while (!ft_strequ(second, tmp->name))
		tmp = tmp->parse_next;
	if (!check_double(tmp->tube, second))
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
	ft_putstr("Hello Tube\n");
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
				return (0);
			if (!(check_exists(data, name_name[0], name_name[1])))
				return (0);
			if (!add_tube(data, name_name[0], name_name[1]))
				return (0);
		}
		ft_list_push_end(&data->lines, line);
	}
	return (1);
}

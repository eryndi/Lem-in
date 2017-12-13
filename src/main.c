/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:19:25 by dwald             #+#    #+#             */
/*   Updated: 2017/12/13 17:16:00 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>
/*
void	test_map(t_lemin *data)
{
	t_room *tmp1;
	t_room *tmp2;


	tmp1 = data->rooms;
	while (!tmp1->is_start)
	{
		tmp1 = tmp1->parse_next;
	}
	tmp2 = tmp1->next_start[1];
	tmp1 = tmp1->next_start[0];
	ft_putstr("\n The first path is: ");
	while (tmp1)
	{
		ft_dprintf(1, "%s - ", tmp1->name);
		tmp1 = tmp1->next;
	}
	ft_putstr("\n The second path is: ");
	while (tmp2)
	{
		ft_dprintf(1, "%s - ", tmp2->name);
		tmp2 = tmp2->next;
	}
	ft_putchar('\n');
	return;

}
*/
static	int	ft_error(void)
{
	ft_putendl(strerror(errno));
	exit(1);
}

int				main(void)
{
	t_lemin		data;
	t_list		*tmp;

//	testing_structure(&data);
//	prepare_structure(&data);
	if (!init(&data) || !parse(&data))
	{
		ft_putstr("ERROR\n");
		return (0);
	}
	while (data.lines)
	{
		tmp = data.lines;
		ft_dprintf(1, "%s\n", data.lines->content);
		free(data.lines->content);
		data.lines = data.lines->next;
		free(tmp);
	}
	ft_putchar('\n');
	algo_launcher(&data);
//test_map(&data);
	ft_putstr("Hello!!\n");	
	decide_paths(&data);
	ft_putstr("assigning ants\n");
	assign_ants(&data, data.s_room);
//	j = 0;
//	while (data.ants[j] != NULL)
//	{
//		ft_dprintf(1, "The ant number %d is starting in room %s\n", data.ants[j]->id, data.ants[j]->start->name);
//		j++;
//	}
	ft_putstr("moving ants\n");
	move_ants(&data);
	free_structures(&data);
	return (0);
}

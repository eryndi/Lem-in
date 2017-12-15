/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:19:25 by dwald             #+#    #+#             */
/*   Updated: 2017/12/15 10:04:15 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

int				main(void)
{
	t_lemin		data;
	t_list		*tmp;

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
ft_dprintf(1, PF_GREEN"algo is finished launching decide paths\n"PF_EOC);
//test_map(&data);	
ft_dprintf(1, "The len is %d\n", data.s_room->next_start[0]->len);
	decide_paths(&data);
	assign_ants(&data, data.s_room);
//	j = 0;
//	while (data.ants[j] != NULL)
//	{
//		ft_dprintf(1, "The ant number %d is starting in room %s\n", data.ants[j]->id, data.ants[j]->start->name);
//		j++;
//	}
	move_ants(&data);
	free_structures(&data);
//	while (42)
//		;
	return (0);
}

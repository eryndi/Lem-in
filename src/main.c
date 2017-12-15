/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:19:25 by dwald             #+#    #+#             */
/*   Updated: 2017/12/15 11:25:30 by dhadley          ###   ########.fr       */
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
	decide_paths(&data);
	assign_ants(&data, data.s_room);
	move_ants(&data);
	free_structures(&data);
	while (42)
		;
	return (0);
}

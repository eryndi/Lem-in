/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:19:25 by dwald             #+#    #+#             */
/*   Updated: 2017/12/05 19:38:18 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"
#include "stdio.h"
static	int	ft_error(void)
{
	ft_putendl(strerror(errno));
	exit(1);
}

int				main(void)
{
	t_lemin		data;
	t_room		*tmp; //for debug
	int			i;
	t_room		*test;

	i = 0;

	ft_dprintf(1, "hello\n"); //
	if (!init(&data) || !parse(&data))
		return (0); //error initialising or parsing;
//	ft_dprintf(1, "The rooms are:\n"); //
	tmp = data.rooms; //
		while (tmp != NULL)//
		{//
//			ft_dprintf(1, "%s\n", tmp->name);//
			tmp = tmp->parse_next;//
		}//
	ft_dprintf(1, "The lines read were:\n");//
	while (data.lines != NULL)
	{
		ft_dprintf(1, "%s\n", data.lines->content);
		data.lines = data.lines->next;
	}
	ft_dprintf(1, "\n\nThe connections are:\n");
	tmp = data.rooms;
	while (tmp)
	{
		ft_dprintf(1, "\n%s is connected to ", tmp->name);
		i = 0;
		while (tmp->connections[i] != NULL)
		{
			test = tmp->connections[i];
			ft_dprintf(1, "- %s ", test->name);
			i++;
		}
		tmp = tmp->parse_next;
	}
	ft_dprintf(1, "good-bye\n");//
	return (0);
}

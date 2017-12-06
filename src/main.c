/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:19:25 by dwald             #+#    #+#             */
/*   Updated: 2017/12/06 18:04:42 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lemin.h>

/*
**			1 _____
**	 	  /			\
** START 0 			 4 END
**	 	  \         /
**			2 ___ 5 
**			  \
**				3
*/

static	void	testing_structure(t_lemin *data)
{
	if ((data->rooms = (t_room*)malloc(sizeof(t_room) * 6)) == NULL)
			exit (1);
	data->rooms[0].name = ft_strdup("room0");
	data->rooms[1].name = ft_strdup("room1");
	data->rooms[2].name = ft_strdup("room2");
	data->rooms[3].name = ft_strdup("room3");
	data->rooms[4].name = ft_strdup("room4");
	data->rooms[5].name = ft_strdup("room5");
	data->rooms[0].is_start = true; 
	data->rooms[1].is_start = false; 
	data->rooms[2].is_start = false; 
	data->rooms[3].is_start = false; 
	data->rooms[4].is_start = false; 
	data->rooms[5].is_start = false; 
	data->rooms[0].is_end = false;
	data->rooms[1].is_end = false;
	data->rooms[2].is_end = false;
	data->rooms[3].is_end = false;
	data->rooms[4].is_end = true;
	data->rooms[5].is_end = false;
	for (int i = 0; i < 6; i++)
	if ((data->rooms[i].connections = (t_room**)malloc(sizeof(t_room) * 4)) == NULL)
		exit (1);
	data->rooms[0].connections[0] = &data->rooms[1];
	data->rooms[0].connections[1] = &data->rooms[2];
	data->rooms[0].connections[2] = NULL;
	data->rooms[1].connections[0] = &data->rooms[0];
	data->rooms[1].connections[1] = &data->rooms[4];
	data->rooms[1].connections[2] = NULL;
	data->rooms[2].connections[0] = &data->rooms[0];
	data->rooms[2].connections[1] = &data->rooms[5];
	data->rooms[2].connections[2] = &data->rooms[3];
	data->rooms[2].connections[3] = NULL;
	data->rooms[3].connections[0] = &data->rooms[2];
	data->rooms[3].connections[1] = NULL;
	data->rooms[4].connections[0] = &data->rooms[1];
	data->rooms[4].connections[1] = &data->rooms[5];
	data->rooms[4].connections[2] = NULL;
	data->rooms[5].connections[0] = &data->rooms[4];
	data->rooms[5].connections[1] = &data->rooms[2];
	data->rooms[5].connections[2] = NULL;
	data->rooms[0].parse_next = &data->rooms[1];
	data->rooms[1].parse_next = &data->rooms[2];
	data->rooms[2].parse_next = &data->rooms[3];
	data->rooms[3].parse_next = &data->rooms[4];
	data->rooms[4].parse_next = &data->rooms[5];
	data->rooms[5].parse_next = NULL;
/*
	for (int i = 0; i < 6; i++)	
	{	
	ft_dprintf(2, "data->rooms[%d]->address = %p\n", i, &data->rooms[i]);
	ft_dprintf(2, "data->rooms[%d]->next    = %p\n",i + 1,data->rooms[i].parse_next);
	}
*/
/*	ft_dprintf(2, "data->rooms[%d]->address = %p\n", 1, &data->rooms[1]);
	ft_dprintf(2, "data->rooms[%d] connection[0] = %p\n", 0, data->rooms[0].connections[0]);
	ft_dprintf(2, "data->rooms[%d]->address = %p\n", 5, &data->rooms[5]);
	ft_dprintf(2, "data->rooms[%d] connection[1] = %p\n", 1, data->rooms[1].connections[1]);*/
}

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
//	testing_structure(&data);
//	prepare_structure(&data);
	if (!init(&data) || !parse(&data))
		return (0);
	algo_launcher(&data, i);
	return (0);
}

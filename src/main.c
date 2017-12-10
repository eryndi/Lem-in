/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:19:25 by dwald             #+#    #+#             */
/*   Updated: 2017/12/10 21:12:44 by dhadley          ###   ########.fr       */
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

	for (int i = 0; i < 6; i++)	
	{	
	ft_dprintf(2, "data->rooms[%d]->address = %p\n", i, &data->rooms[i]);
	ft_dprintf(2, "data->rooms[%d]->next    = %p\n",i + 1,data->rooms[i].parse_next);
	}

	ft_dprintf(2, "data->rooms[%d]->address = %p\n", 1, &data->rooms[1]);
	ft_dprintf(2, "data->rooms[%d] connection[0] = %p\n", 0, data->rooms[0].connections[0]);
	ft_dprintf(2, "data->rooms[%d]->address = %p\n", 5, &data->rooms[5]);
	ft_dprintf(2, "data->rooms[%d] connection[1] = %p\n", 1, data->rooms[1].connections[1]);
}
*/
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
	int			i;
	//int			j;

	i = 0;
//	testing_structure(&data);
//	prepare_structure(&data);
	if (!init(&data) || !parse(&data))
		return (0);
	while (data.lines)
	{
		tmp = data.lines;
		ft_dprintf(1, "%s\n", data.lines->content);
		free(data.lines->content);
		data.lines = data.lines->next;
		free(tmp);
	}
	ft_putchar('\n');
	algo_launcher(&data, i);
//test_map(&data);	
	decide_paths(&data);
	assign_ants(&data);
//	j = 0;
//	while (data.ants[j] != NULL)
//	{
//		ft_dprintf(1, "The ant number %d is starting in room %s\n", data.ants[j]->id, data.ants[j]->start->name);
//		j++;
//	}
	move_ants(&data);
	free_structures(&data);
	return (0);
}

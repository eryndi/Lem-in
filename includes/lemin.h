/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:41:40 by dwald             #+#    #+#             */
/*   Updated: 2017/12/07 18:54:03 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H

/*
** ------------------------------ Librairies -----------------------------------
*/

# include "libft.h"
# include <errno.h>

/*
** ---------------------------- lem_in variables -------------------------------
*/

typedef struct		s_tube
{
	char			*name;
	struct s_tube	*next;
}					t_tube;

typedef struct		s_room
{
	char			*name;
	bool			is_start;
	bool			is_end;
	char			*coord_x;
	char			*coord_y;
	bool			occupied;
	struct s_room	*next;
	struct s_room	**next_start;
	struct s_room	**connections;
	bool			is_enqueued;
	bool			is_dequeued;
	int				is_path;
	int				len;
	struct s_room	*parse_next;
	t_tube			*tube;
}					t_room;

typedef struct		s_ant
{
	char			*name;
	char			*room_name;
}					t_ant;

typedef	struct		s_lemin
{
	t_ant			*ants;
	t_room			*rooms;
	int				num_ants;
	bool			start;
	bool			end;
	t_list			*lines;

}					t_lemin;

/*
** ------------------------------- algo functions ------------------------------
*/

void    algo_launcher(t_lemin *data, int i);
void    prepare_structure(t_lemin *data);

/*
** ---------------------------- parsing functions ------------------------------
*/

int					init(t_lemin *data);
int					init_room(t_room *room);
int					parse(t_lemin *data);
int					parse_rooms(t_lemin *data);
int					parse_tubes(t_lemin *data, char *line);
int					make_connections(t_lemin *data);

#endif

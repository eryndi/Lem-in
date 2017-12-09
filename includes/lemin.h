/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:41:40 by dwald             #+#    #+#             */
/*   Updated: 2017/12/09 19:24:08 by dhadley          ###   ########.fr       */
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
	struct s_room	**connections;
	bool			is_checked;
	int				is_path;
	int				len;
	int				nb_ants;
	struct s_room	**next_start;
	struct s_room	*parse_next;
	t_tube			*tube;
}					t_room;

typedef struct		s_ant
{
	int				id;
	t_room			*start;
	bool			print;
	bool			finished;
}					t_ant;

typedef	struct		s_lemin
{
	t_ant			**ants;
	t_room			*rooms;
	int				num_ants;
	bool			start;
	bool			end;
	t_list			*lines;

}					t_lemin;

/*
** --------------------------- player main functions ---------------------------
*/

int					init(t_lemin *data);
int					init_room(t_room *room);
int					parse(t_lemin *data);
int					parse_rooms(t_lemin *data);
int					parse_tubes(t_lemin *data, char *line);
int					make_connections(t_lemin *data);

void				remove_extra_paths(t_lemin *data, t_room *start_room);

void				assign_ants(t_lemin *data, t_room *start_room);

#endif

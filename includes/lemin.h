/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:41:40 by dwald             #+#    #+#             */
/*   Updated: 2017/12/02 20:22:32 by dhadley          ###   ########.fr       */
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
	struct s_room	*parse_next;
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
** --------------------------- player main functions ---------------------------
*/

int					init(t_lemin *data);
int					parse(t_lemin *data);
int					parse_rooms(t_lemin *data);

#endif

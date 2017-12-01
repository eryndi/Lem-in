/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:41:40 by dwald             #+#    #+#             */
/*   Updated: 2017/12/01 16:27:29 by dhadley          ###   ########.fr       */
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
	int				coord_x;
	int				coord_y;
	bool			occupied;
	struct s_room	*next;
	struct s_room	**connections;
	int				is_path;
}					t_room;

typedef struct		s_ant
{
	char			*name;
	char			*room_name;
}					t_ant;

typedef	struct		s_lemin
{
	t_ant			*ants;
	t_rooms			*rooms;
	int				num_ants;
	bool			start;
	bool			end;
	t_list			*lines;

}					t_lemin;

/*
** --------------------------- player main functions ---------------------------
*/

#endif

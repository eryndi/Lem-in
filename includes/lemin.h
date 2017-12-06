/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/29 14:41:40 by dwald             #+#    #+#             */
/*   Updated: 2017/12/06 13:52:17 by dwald            ###   ########.fr       */
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
	struct s_room	**next_start;
	struct s_room	**connections;
	int				is_path;
	int				len;
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
** ------------------------------- algo functions ------------------------------
*/

void    algo(t_lemin *data);
void    prepare_structure(t_lemin *data);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 11:21:17 by dwald             #+#    #+#             */
/*   Updated: 2017/12/15 12:10:44 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	*color_that_ant(int id, char *s)
{
	 ft_dprintf(1, " HELLO ");
	if (id % 7 == 1)
		s = ft_strcat(s, PF_RED);
	if (id % 7 == 2)
		s = ft_strcat(s, PF_GREEN);
	if (id % 7 == 3)
		s = ft_strcat(s, PF_YELLOW);
	if (id % 7 == 4)
		s = ft_strcat(s, PF_BLUE);
	if (id % 7 == 5)
		s = ft_strcat(s, PF_MAGENTA);
	if (id % 7 == 6)
		s = ft_strcat(s, PF_CYAN);
	return (s);
}

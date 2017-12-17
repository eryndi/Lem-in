/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 11:21:17 by dwald             #+#    #+#             */
/*   Updated: 2017/12/15 12:23:28 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lemin.h"

char	*color_that_ant(int id, char *s)
{
	if (id % 6 == 1)
		s = ft_strcpy(s, PF_RED);
	if (id % 6 == 2)
		s = ft_strcpy(s, PF_GREEN);
	if (id % 6 == 3)
		s = ft_strcpy(s, PF_YELLOW);
	if (id % 6 == 4)
		s = ft_strcpy(s, PF_BLUE);
	if (id % 6 == 5)
		s = ft_strcpy(s, PF_MAGENTA);
	if (id % 6 == 0)
		s = ft_strcpy(s, PF_CYAN);
	return (s);
}

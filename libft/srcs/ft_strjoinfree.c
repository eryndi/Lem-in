/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:37:58 by dwald             #+#    #+#             */
/*   Updated: 2017/09/26 17:51:08 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, int free_malloc)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	new = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	if (new == NULL)
		return (NULL);
	ft_strncpy(new, s1, ft_strlen(s1));
	ft_strncat(new, s2, ft_strlen(s2));
	if (free_malloc == 3)
	{
		ft_strdel(&s1);
		ft_strdel(&s2);
	}
	else if (free_malloc == 2)
		ft_strdel(&s2);
	else if (free_malloc == 1)
		ft_strdel(&s1);
	return (new);
}

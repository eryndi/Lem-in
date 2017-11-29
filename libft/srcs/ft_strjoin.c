/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 18:11:48 by dwald             #+#    #+#             */
/*   Updated: 2016/12/08 16:04:30 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*new;

	if (s1 && s2)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if ((new = ft_strnew(len)) == NULL)
			return (NULL);
		ft_bzero(new, len);
		new = ft_strcat(new, s1);
		new = ft_strcat(new, s2);
		return (new);
	}
	return (NULL);
}

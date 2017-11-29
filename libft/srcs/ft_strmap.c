/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 15:00:03 by dwald             #+#    #+#             */
/*   Updated: 2016/12/07 16:20:16 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*temp;
	int		len;

	if (s && f)
	{
		len = ft_strlen(s);
		if ((temp = ft_strnew(len)) == NULL)
			return (NULL);
		else
			while (*s)
				*temp++ = (*f)(*s++);
		return (temp - len);
	}
	return (NULL);
}

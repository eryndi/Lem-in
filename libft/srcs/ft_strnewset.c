/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:44:28 by dwald             #+#    #+#             */
/*   Updated: 2017/09/29 15:03:55 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnewset(int c, size_t len)
{
	char	*str;

	if ((str = ft_strnew(len)) == NULL)
		return (NULL);
	c = (unsigned char)c;
	while (len)
		((unsigned char*)str)[--len] = c;
	return (str);
}

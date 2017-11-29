/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:34:01 by dwald             #+#    #+#             */
/*   Updated: 2016/12/14 12:15:52 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	if (!*little)
		return ((char*)big);
	while (*big)
	{
		if (ft_strnequ(big, little, ft_strlen(little)))
			return ((char*)big);
		big++;
	}
	return (NULL);
}

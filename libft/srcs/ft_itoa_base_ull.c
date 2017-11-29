/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_ull.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:18:15 by dwald             #+#    #+#             */
/*   Updated: 2017/09/29 16:24:28 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_ull(unsigned long long int value, int base)
{
	char	*s;
	char	tmp[65];
	char	*representation;
	int		i;

	representation = "0123456789abcdef";
	ft_bzero(tmp, sizeof(tmp));
	i = 0;
	if (value == 0)
	{
		s = ft_strdup("0");
		return (s);
	}
	if (base < 2 || base > 16)
		return (NULL);
	while (value != 0)
	{
		tmp[i++] = representation[value % base];
		value = value / base;
	}
	s = ft_strdup(tmp);
	s = ft_strrev(s);
	return (s);
}

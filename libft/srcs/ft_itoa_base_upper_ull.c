/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_upper_ull.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:18:15 by dwald             #+#    #+#             */
/*   Updated: 2017/09/29 16:25:20 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_upper_ull(unsigned long long value, int base)
{
	char	*s;
	char	tmp[65];
	char	*representation;
	int		i;

	representation = "0123456789ABCDEF";
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

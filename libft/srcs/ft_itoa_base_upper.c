/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_upper.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 17:18:15 by dwald             #+#    #+#             */
/*   Updated: 2017/09/29 16:40:23 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa_base_upper(long long int value, int base)
{
	char					*s;
	char					tmp[65];
	unsigned long long int	nb;
	char					*representation;
	int						i;

	nb = (value < 0) ? -value : value;
	if (value == 0)
		return (ft_strdup("0"));
	representation = "0123456789ABCDEF";
	ft_bzero(tmp, sizeof(tmp));
	i = 0;
	if (base < 2 || base > 16)
		return (NULL);
	while (nb != 0)
	{
		tmp[i++] = representation[nb % base];
		nb = nb / base;
	}
	if (value < 0 && base == 10)
		tmp[i] = '-';
	s = ft_strdup(tmp);
	s = ft_strrev(s);
	return (s);
}

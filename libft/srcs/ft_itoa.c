/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:38:44 by dwald             #+#    #+#             */
/*   Updated: 2016/12/15 19:57:40 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	unsigned int	nb;
	char			*str;
	int				len;
	int				i;

	len = ft_countdigits(n);
	if ((str = ft_strnew(len)) == NULL)
		return (str);
	nb = n;
	i = 0;
	if (n < 0)
	{
		str[len - 1] = '-';
		nb = -n;
	}
	while (nb >= 10)
	{
		str[i++] = (nb % 10) + '0';
		nb = (nb / 10);
	}
	if (nb < 10)
		str[i] = (nb + '0');
	str = ft_strrev(str);
	return (str);
}

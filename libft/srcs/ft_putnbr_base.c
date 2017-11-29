/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 11:16:19 by dwald             #+#    #+#             */
/*   Updated: 2017/09/15 14:53:25 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base(long long int n, unsigned int base)
{
	unsigned long long int	nb;
	char					*representation;

	representation = "0123456789ABCDEF";
	nb = n;
	if (base < 2 || base > 16)
	{
		ft_putendl("ERROR: ft_putnbr_base bad base input");
		return ;
	}
	if (n < 0)
	{
		nb = -n;
		ft_putchar('-');
	}
	if (nb >= base)
	{
		ft_putnbr_base(nb / base, base);
		ft_putchar(representation[nb % base]);
	}
	if (nb < base)
		ft_putchar(representation[nb]);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_part_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/15 17:44:52 by dwald             #+#    #+#             */
/*   Updated: 2017/10/12 18:03:24 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

void	ft_len(t_var *var)
{
	if ((ft_strncmp(var->format, "hh", 2) == 0)
	|| (ft_strncmp(var->format, "ll", 2) == 0))
	{
		var->len = (ft_strncmp(var->format, "ll", 2) == 0) ? len_ll : len_hh;
		var->format += 2;
		return ;
	}
	if (*var->format == 'h')
		var->len = len_h;
	else if (*var->format == 'l')
		var->len = len_l;
	else if (*var->format == 'j')
		var->len = len_j;
	else if (*var->format == 'z')
		var->len = len_z;
	else
	{
		var->len = 6;
		return ;
	}
	var->format++;
	return ;
}

/*
**	The order of conversions is divided for following type specifiers in order:
**	di + hh, u, o, x, X.
*/

void	ft_cast_char(t_var *var, va_list *ap)
{
	if (var->type == 0)
	{
		var->u_val.nbr = (char)va_arg(*ap, int);
		if (var->u_val.nbr != 0 || var->precision != 0)
		{
			if ((var->stored_flags[2] == true || var->precision > 1)
			&& var->u_val.nbr < 0)
				var->stem = ft_itoa_base((char)(-var->u_val.nbr), 10);
			else
				var->stem = ft_itoa_base((char)var->u_val.nbr, 10);
		}
	}
	else
		var->u_val.nbr = (unsigned char)va_arg(*ap, int);
	if (var->type == 2 && (var->u_val.nbr != 0 || var->precision != 0))
		var->stem = ft_itoa_base((unsigned char)var->u_val.nbr, 10);
	else if (var->type == 4 && (var->u_val.nbr != 0 || var->precision != 0))
		var->stem = ft_itoa_base((unsigned char)var->u_val.nbr, 8);
	else if (var->type == 6 && (var->u_val.nbr != 0 || var->precision != 0))
		var->stem = ft_itoa_base((unsigned char)var->u_val.nbr, 16);
	else if (var->type == 7 && (var->u_val.nbr != 0 || var->precision != 0))
		var->stem = ft_itoa_base_upper((unsigned char)var->u_val.nbr, 16);
	return ;
}

/*
**	The order of conversions is divided for following type specifiers in order:
**	di + h, u, o, x, X.
*/

void	ft_cast_short(t_var *var, va_list *ap)
{
	if (var->type == 0)
	{
		var->u_val.nbr = (short)va_arg(*ap, int);
		if (var->u_val.nbr != 0 || var->precision != 0)
		{
			if ((var->stored_flags[2] == true || var->precision > 1)
			&& var->u_val.nbr < 0)
				var->stem = ft_itoa_base((short int)(-var->u_val.nbr), 10);
			else
				var->stem = ft_itoa_base((short)var->u_val.nbr, 10);
		}
	}
	else
		var->u_val.nbr = (unsigned short)va_arg(*ap, int);
	if (var->type == 2 && (var->u_val.nbr != 0 || var->precision != 0))
		var->stem = ft_itoa_base((unsigned short)var->u_val.nbr, 10);
	else if (var->type == 4 && (var->u_val.nbr != 0 || var->precision != 0))
		var->stem = ft_itoa_base((unsigned short)var->u_val.nbr, 8);
	else if (var->type == 6 && (var->u_val.nbr != 0 || var->precision != 0))
		var->stem = ft_itoa_base((unsigned short)var->u_val.nbr, 16);
	else if (var->type == 7 && (var->u_val.nbr != 0 || var->precision != 0))
		var->stem = ft_itoa_base_upper((unsigned short)var->u_val.nbr, 16);
	return ;
}

/*
**	The order of conversions is divided for following type specifiers in order:
**	di + l, u, o, x, X.
*/

void	ft_cast_long(t_var *var, va_list *ap)
{
	if (var->type == 0)
	{
		var->u_val.nbr = va_arg(*ap, long);
		if (var->u_val.nbr != 0 || var->precision != 0)
		{
			if ((var->stored_flags[2] == true || var->precision > 1)
			&& var->u_val.nbr < 0)
				var->stem = ft_itoa_base((long)(-var->u_val.nbr), 10);
			else
				var->stem = ft_itoa_base((long)var->u_val.nbr, 10);
		}
	}
	else
		var->u_val.nbr = va_arg(*ap, unsigned long);
	if (var->type == 2 && (var->u_val.nbr != 0 || var->precision != 0))
		var->stem = ft_itoa_base_ull((unsigned long)var->u_val.nbr, 10);
	else if (var->type == 4 && (var->u_val.nbr != 0 || var->precision != 0))
		var->stem = ft_itoa_base_ull((unsigned long)var->u_val.nbr, 8);
	else if (var->type == 6 && (var->u_val.nbr != 0 || var->precision != 0))
		var->stem = ft_itoa_base_ull((unsigned long)var->u_val.nbr, 16);
	else if (var->type == 7 && (var->u_val.nbr != 0 || var->precision != 0))
		var->stem = ft_itoa_base_upper_ull((unsigned long)var->u_val.nbr, 16);
	return ;
}

/*
**	The order of conversions is divided for following type specifiers in order:
**	di + ll, u, o, x, X.
*/

void	ft_cast_longlong(t_var *var, va_list *ap)
{
	if (var->type == 0)
	{
		var->u_val.nbr = va_arg(*ap, long long);
		if (var->u_val.nbr != 0 || var->precision != 0)
		{
			if ((var->stored_flags[2] == true || var->precision > 1)
			&& var->u_val.nbr < 0)
				var->stem = ft_itoa_base((long long)(-var->u_val.nbr), 10);
			else
				var->stem = ft_itoa_base((long long)var->u_val.nbr, 10);
		}
	}
	else
		var->u_val.nbr = va_arg(*ap, unsigned long long);
	if (var->type == 2 && (var->u_val.nbr != 0 || var->precision != 0))
		var->stem = ft_itoa_base_ull((unsigned long long)var->u_val.nbr, 10);
	else if (var->type == 4 && (var->u_val.nbr != 0 || var->precision != 0))
		var->stem = ft_itoa_base_ull((unsigned long long)var->u_val.nbr, 8);
	else if (var->type == 6 && (var->u_val.nbr != 0 || var->precision != 0))
		var->stem = ft_itoa_base_ull((unsigned long long)var->u_val.nbr, 16);
	else if (var->type == 7 && (var->u_val.nbr != 0 || var->precision != 0))
		var->stem = ft_itoa_base_upper_ull((unsigned long long)var->u_val.nbr,
		16);
	return ;
}

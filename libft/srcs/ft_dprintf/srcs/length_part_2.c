/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   length_part_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/17 11:54:35 by dwald             #+#    #+#             */
/*   Updated: 2017/10/12 18:03:35 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

/*
**	Table of booleans stores flags (#, zero, plus, minus, space)
**  stored_flags[0] stands for  precision  .
**  stored_flags[1] stands for  hash  flag #
**  stored_flags[2] stands for  zero  flag 0
**  stored_flags[3] stands for  minus flag -
**  stored_flags[4] stands for  plus  flag +
**  stored_flags[5] stands for  space flag " "
**  stored_flags[6] stands for  left adjusted space padding
*/

/*
** ------------------------------ type specifiers ------------------------------
** spec_di = 0  spec_D(ld) = 1  spec_u = 2  spec_U(lu) = 3  spec_o = 4
** spec_O(lo) = 5   spec_x = 6  spec_X = 7  spec_c = 8  spec_C(lc) = 9
** spec_s = 10  spec_S = 11 spec_p = 12 no_spec = 13
*/

/*
**	Following set of functions handle length specifiers with type specifiers
**  for printf function. Returns converted value in form of a acllocated string.
*/

void	ft_no_cast(t_var *var, va_list *ap)
{
	if (var->type == 0)
	{
		var->u_val.nbr = (int)va_arg(*ap, int);
		if (var->u_val.nbr != 0 || var->precision != 0)
		{
			if (((var->stored_flags[2] == true && var->stored_flags[3] == false)
			|| var->precision >= 0) && var->u_val.nbr < 0)
				var->stem = ft_itoa_base((int)(-var->u_val.nbr), 10);
			else
				var->stem = ft_itoa_base((int)var->u_val.nbr, 10);
		}
	}
	else
		var->u_val.nbr = (unsigned int)va_arg(*ap, unsigned int);
	if (var->type == 2 && (var->u_val.nbr != 0 || var->precision != 0))
		var->stem = ft_itoa_base((unsigned int)var->u_val.nbr, 10);
	else if (var->type == 4 && (var->u_val.nbr != 0 || var->precision != 0))
		var->stem = ft_itoa_base((unsigned int)var->u_val.nbr, 8);
	else if (var->type == 6 && (var->u_val.nbr != 0 || var->precision != 0))
		var->stem = ft_itoa_base((unsigned int)var->u_val.nbr, 16);
	else if (var->type == 7 && (var->u_val.nbr != 0 || var->precision != 0))
		var->stem = ft_itoa_base_upper((unsigned int)var->u_val.nbr, 16);
	return ;
}

void	ft_cast_intmax_t(t_var *var, va_list *ap)
{
	if (var->type == 0)
	{
		var->u_val.nbr = (intmax_t)va_arg(*ap, intmax_t);
		if (var->u_val.nbr != 0 || var->precision != 0)
		{
			if ((var->stored_flags[2] == true || var->precision > 1)
			&& var->u_val.nbr < 0)
				var->stem = ft_itoa_base((intmax_t)(-var->u_val.nbr), 10);
			else
				var->stem = ft_itoa_base((intmax_t)var->u_val.nbr, 10);
		}
	}
	else
		var->u_val.nbr = (uintmax_t)va_arg(*ap, uintmax_t);
	if (var->type == 2 && (var->u_val.nbr != 0 || var->precision != 0))
		var->stem = ft_itoa_base_ull((uintmax_t)var->u_val.nbr, 10);
	else if (var->type == 4 && (var->u_val.nbr != 0 || var->precision != 0))
		var->stem = ft_itoa_base_ull((uintmax_t)var->u_val.nbr, 8);
	else if (var->type == 6 && (var->u_val.nbr != 0 || var->precision != 0))
		var->stem = ft_itoa_base_ull((uintmax_t)var->u_val.nbr, 16);
	else if (var->type == 7 && (var->u_val.nbr != 0 || var->precision != 0))
		var->stem = ft_itoa_base_upper_ull((uintmax_t)var->u_val.nbr, 16);
	return ;
}

void	ft_cast_size_t(t_var *var, va_list *ap)
{
	var->u_val.nbr = va_arg(*ap, size_t);
	if (var->u_val.nbr == 0 && var->precision == 0)
		return ;
	else if (var->type == 0)
		var->stem = ft_itoa_base((size_t)var->u_val.nbr, 10);
	else if (var->type == 2)
		var->stem = ft_itoa_base_ull((size_t)var->u_val.nbr, 10);
	else if (var->type == 4)
		var->stem = ft_itoa_base_ull((size_t)var->u_val.nbr, 8);
	else if (var->type == 6)
		var->stem = ft_itoa_base_ull((size_t)var->u_val.nbr, 16);
	else if (var->type == 7)
		var->stem = ft_itoa_base_upper_ull((size_t)var->u_val.nbr, 16);
	return ;
}

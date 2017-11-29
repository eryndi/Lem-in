/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 10:32:42 by dwald             #+#    #+#             */
/*   Updated: 2017/10/12 18:02:36 by dwald            ###   ########.fr       */
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
**	'#' The value should be converted to an 'alternate form'.
**	For c, d, i, n, p, s, and u conversions, this option has no effect.
**	For o and O conversions, the precision of the number is increased to force
**	the first character of the output string to a zero.
**	For x and X conversions, a non-zero result has the string `0x' (or `0X'
**	for X conversions) prepended to it.  For a, A, e, E, f, F, g, and G conver-
**	sions, the result will always contain a decimal point, even if no digits
**	follow it (normally, a decimal point appears in the results of those conver-
**	sions only if a digit follows). For g and G conversions, trailing zeros are
**	not removed from the result as they would otherwise be.
*/

void	ft_hash_flag(t_var *var)
{
	if ((var->type == 4 || var->type == 5) && var->precision < 1)
	{
		if (var->u_val.nbr == 0 && var->precision == 0)
		{
			if (var->stem == NULL)
				var->stem = ft_strdup("0");
			else
				var->stem = ft_strjoinfree("0", var->stem, 2);
		}
		else if (var->u_val.nbr != 0)
			var->stem = ft_strjoinfree("0", var->stem, 2);
	}
	else if (var->type == 6 && var->u_val.nbr != 0)
		var->prefix = (var->prefix == NULL) ? ft_strdup("0x") :
		ft_strjoinfree("0x", var->prefix, 2);
	else if (var->type == 7 && var->u_val.nbr != 0)
		var->prefix = (var->prefix == NULL) ? ft_strdup("0X") :
		ft_strjoinfree("0X", var->prefix, 2);
	return ;
}

/*
**	'0' (zero) Zero padding. For all conversions except n, the converted value
**	is padded on the left with zeros rather than blanks. If a precision is given
**	with a numeric conversion (d, i, o, u, i, x, and X), the 0 flag is ignored.
*/

void	ft_zero_flag(t_var *var)
{
	int		len;

	if (var->stored_flags[3] == true)
		return ;
	if (var->type < 8 && var->stored_flags[0] == true)
		return ;
	if ((len = ft_padding_length(var)) <= 0 && var->u_val.nbr >= 0)
		return ;
	if (var->u_val.nbr < 0 && var->type < 2)
	{
		var->prefix = ft_strnew(len);
		var->prefix[0] = '-';
		if (len > 0)
			ft_memset((void*)&var->prefix[1], '0', len - 1);
	}
	else
	{
		if (var->prefix == NULL)
			var->prefix = ft_strnewset('0', len);
		else
			var->prefix = ft_strjoin(var->prefix, ft_strnewset('0', len));
	}
	return ;
}

/*
**	'-' A negative field width flag; the converted value is to be left adjusted
**	on the field boundary. Except for n conversions, the converted value is
**	padded on the right with blanks, rather than on the left with blanks or
**	zeros.  A - overrides a 0 if both are given.
*/

void	ft_minus_flag(t_var *var)
{
	int	len;

	if ((len = ft_padding_length(var)) == 0 && var->u_val.nbr >= 0)
		return ;
	var->suffix = ft_strnew(len);
	var->suffix = ft_memset((void*)var->suffix, ' ', len);
	return ;
}

/*
** '+' A sign must always be placed before a number produced by a signed
**	conversion. A + overrides a space if both are used. Behaviour is udefined
**	for conversions with c, s, u, x, X, o, O, p. Applies only on d, i, D.
*/

void	ft_plus_flag(t_var *var)
{
	if (var->type <= 1 && var->u_val.nbr >= 0)
	{
		if (var->prefix == NULL)
			var->prefix = ft_strdup("+");
		else
			var->prefix = ft_strjoinfree("+", var->prefix, 2);
	}
	return ;
}

/*
**	' ' (space) A blank should be left before a positive number produced by
**	a signed conversion (a, A, d, e, E, f, F, g, G, or i).
*/

void	ft_space_flag(t_var *var)
{
	if (var->type <= 1 && var->stored_flags[4] == false && var->u_val.nbr >= 0)
	{
		if (var->prefix != NULL)
			var->prefix = ft_strjoinfree(" ", var->prefix, 2);
		else
			var->prefix = ft_strdup(" ");
	}
	return ;
}

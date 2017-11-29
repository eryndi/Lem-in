/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_and_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 15:55:42 by dwald             #+#    #+#             */
/*   Updated: 2017/10/12 18:03:50 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

/*
**	Table of booleans "stored_flags" stores flags (#, zero, plus, minus, space)
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

int				ft_padding_length(t_var *var)
{
	int	len;

	if (var->type == 8 && var->stem == '\0')
		len = 1;
	else if (var->stored_flags[1] == true)
		len = ft_strlen(var->stem) + ft_strlen(var->prefix);
	else
		len = ft_strlen(var->stem);
	if ((var->stored_flags[4] == true || var->stored_flags[5] == true)
	&& var->u_val.nbr >= 0 && var->type != 13)
		len++;
	len = ((var->width - len) > 0) ? (var->width - len) : 0;
	return (len);
}

/*
** Applies right justified padding with spaces if width is precised.
** Does not aplly on numerals with present zero flag.
*/

void			ft_space_padding(t_var *var)
{
	int		len;

	if (((var->type < 8 && var->stored_flags[2] == true)
	&& (var->precision == -1)) || (var->stored_flags[3] == true))
		return ;
	if (var->stored_flags[2] == 1 && var->stored_flags[0] == 1 && var->type > 8)
		return ;
	if (var->stored_flags[2] == true && var->type >= 8 && var->type <= 11)
		return ;
	if (var->stored_flags[2] == true && var->type == 13)
		return ;
	if ((len = ft_padding_length(var)) == 0)
		return ;
	if (var->prefix != NULL)
		var->prefix = ft_strjoinfree(ft_strnewset(' ', len), var->prefix, 2);
	else
	{
		var->prefix = ft_strnew(len);
		var->prefix = ft_memset((void*)var->prefix, ' ', len);
	}
}

static	void	ft_precision_numbers(t_var *var)
{
	int		len;
	char	*s;

	len = var->precision - ft_strlen(var->stem);
	if (var->type < 2 && var->u_val.nbr < 0)
	{
		if (len == 1)
			var->stem = ft_strjoinfree("-0", var->stem, 2);
		else if (len > 1)
		{
			s = ft_strnew(len + 1);
			s[0] = '-';
			ft_memset((void*)&s[1], '0', (len));
			var->stem = ft_strjoinfree(s, var->stem, 3);
		}
		else if (len <= 0 && var->stem[0] != '-')
			var->stem = ft_strjoinfree("-", var->stem, 2);
	}
	else if (var->u_val.nbr >= 0 && len > 0)
		var->stem = ft_strjoinfree(ft_strnewset('0', len), var->stem, 3);
}

void			ft_precision(t_var *var)
{
	if (var->stored_flags[0] == true && var->precision != -1)
	{
		if (var->type < 8)
			ft_precision_numbers(var);
		if ((var->type == 10) && ((int)ft_strlen(var->stem) > var->precision))
			var->stem = ft_strndupfree(var->stem, var->precision, 1);
	}
}

/*
** width: An optional decimal digit string specifying a minimum field width. If
**        the converted value has fewer characters than the field width, it will
**        be padded with spaces on the left (or right, if the left-adjustment
**        flag has been given) to fill out the field width.
**
** prec: An optional precision, in the form of a period. followed by an
**       optional digit string. If the digit string is omitted, the precision
**       is taken as zero. This gives the minimum number of digits to appear
**       for d, i, o, u, x, and X conversions, the number of digits to appear
**       after the decimal-point for a, A, e, E, f, and F conversions, the maxi-
**       mum number of significant digits for g and G conversions, or the maxi-
**       mum number of characters to be printed from a string for s conversions.
*/

void			ft_width_and_precision(t_var *var)
{
	char	str[33];
	int		i;

	i = 0;
	ft_memset(str, '\0', 33);
	while (*var->format >= '0' && *var->format <= '9'
	&& var->stored_flags[6] != true)
	{
		str[i++] = *var->format;
		var->format++;
	}
	var->width = (var->stored_flags[6] != true) ? ft_atoi(str) : var->width;
	if (var->stored_flags[6] != true)
		var->stored_flags[6] = (var->width != 0) ? true : false;
	if (*var->format == '.')
	{
		i = 0;
		ft_memset(str, '\0', 33);
		while (*(++var->format) >= '0' && *var->format <= '9')
			str[i++] = *var->format;
		var->precision = ft_atoi(str);
		var->stored_flags[0] = (var->precision != -1) ? true : false;
	}
}

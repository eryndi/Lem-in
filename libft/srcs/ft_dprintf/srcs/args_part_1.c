/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_part_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 15:12:26 by dwald             #+#    #+#             */
/*   Updated: 2017/10/19 14:22:00 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

static	void	ft_arg_cast(t_var *var, const t_cast *t_casting, va_list *ap)
{
	while (t_casting->length <= 6)
	{
		if (t_casting->length == var->len)
		{
			(t_casting->cast_ptr)(var, ap);
			break ;
		}
		t_casting++;
	}
	return ;
}

void			ft_int_arg(va_list *ap, t_var *variable)
{
	const t_cast t_casting[7] = {
		{ 0, ft_cast_char },
		{ 1, ft_cast_short },
		{ 2, ft_cast_long },
		{ 3, ft_cast_longlong },
		{ 4, ft_cast_intmax_t },
		{ 5, ft_cast_size_t },
		{ 6, ft_no_cast },
	};

	if (*variable->format == 'd' || *variable->format == 'i')
		variable->type = spec_di;
	if (*variable->format == 'u')
		variable->type = spec_u;
	if (*variable->format == 'o')
		variable->type = spec_o;
	if (*variable->format == 'x')
		variable->type = spec_x;
	if (*variable->format == 'X')
		variable->type = spec_X;
	ft_arg_cast(variable, t_casting, ap);
	return ;
}

void			ft_long_arg(va_list *ap, t_var *var)
{
	if (*var->format == 'D')
	{
		var->u_val.nbr = (long)va_arg(*ap, long);
		var->type = spec_D;
		if (var->u_val.nbr < 0 && (var->stored_flags[2] == true
		|| var->precision > 1))
			var->stem = ft_itoa_base(-var->u_val.nbr, 10);
		else if (var->u_val.nbr != 0 || var->precision != 0)
			var->stem = ft_itoa_base((long)var->u_val.nbr, 10);
	}
	if (*var->format == 'O')
	{
		var->u_val.nbr = (unsigned long)va_arg(*ap, unsigned long);
		var->type = spec_O;
		if (var->u_val.nbr != 0 || var->precision != 0)
			var->stem = ft_itoa_base_ull((unsigned long)var->u_val.nbr, 8);
	}
	if (*var->format == 'U')
	{
		var->u_val.nbr = (unsigned long)va_arg(*ap, unsigned long);
		var->type = spec_U;
		if (var->u_val.nbr != 0 || var->precision != 0)
			var->stem = ft_itoa_base_ull((unsigned long)var->u_val.nbr, 10);
	}
	return ;
}

void			ft_char_arg(va_list *ap, t_var *variable)
{
	char c;

	if (*variable->format == 'c')
	{
		variable->type = spec_c;
		c = (char)va_arg(*ap, int);
		variable->stem = ft_strndup(&c, 1);
	}
	else if (*variable->format == 'C' || variable->len == 2)
	{
		variable->type = spec_C;
		c = va_arg(*ap, long long);
		variable->stem = ft_strndup(&c, 1);
	}
	else if (*variable->format == 's')
	{
		variable->type = spec_s;
		variable->stem = ft_strdup(va_arg(*ap, char*));
		if (variable->stem == NULL)
			variable->stem = ft_strdup("(null)");
	}
	if (*(variable->stem) == '\0')
		variable->stem = ft_strdup(0);
}

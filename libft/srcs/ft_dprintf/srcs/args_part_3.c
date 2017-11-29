/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_part_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/20 10:12:04 by dwald             #+#    #+#             */
/*   Updated: 2017/10/12 18:02:00 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

void	ft_sort_argument_type(t_var *var, va_list *ap)
{
	const			t_conv	*t_ptr;
	static	const	t_conv	t_args_conversion[] = {
		{"diouxX", ft_int_arg},
		{"DOU", ft_long_arg},
		{"Ccs", ft_char_arg},
		{"p", ft_ptr_arg},
		{"0", NULL}
	};

	t_ptr = t_args_conversion;
	while (*(t_ptr->arg) != '0')
	{
		if (ft_strchr(t_ptr->arg, *var->format))
		{
			(t_ptr->fptr)(ap, var);
			break ;
		}
		t_ptr++;
		if (*(t_ptr->arg) == '0')
		{
			var->type = no_spec;
			var->stem = ft_strndup(var->format, 1);
		}
	}
}

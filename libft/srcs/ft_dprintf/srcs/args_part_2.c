/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_part_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/21 13:38:42 by dwald             #+#    #+#             */
/*   Updated: 2017/10/12 18:01:47 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

void	ft_ptr_arg(va_list *ap, t_var *variable)
{
	char *tmp;

	if (*variable->format == 'p')
		variable->u_val.p = va_arg(*ap, void*);
	variable->type = spec_p;
	tmp = (variable->u_val.p == NULL) ?
	ft_strdup("0x0") :
	ft_strjoinfree("0x",
	ft_itoa_base_ull((unsigned long long)variable->u_val.p, 16), 2);
	variable->stem = ft_strdupfree(tmp, 1);
}

void	ft_pct_arg(t_var *variable)
{
	char c;

	c = '%';
	if (*variable->format == '%')
		variable->stem = ft_strndup(&c, 1);
}

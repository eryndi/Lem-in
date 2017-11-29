/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliary_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/24 13:30:29 by dwald             #+#    #+#             */
/*   Updated: 2017/10/19 14:12:27 by dwald            ###   ########.fr       */
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

void	ft_sort_flags(t_var *var)
{
	if (ft_strchr("#0+- ", *var->format))
	{
		if (var->stored_flags[1] != true)
			var->stored_flags[1] = (*var->format == '#') ? true : false;
		if (var->stored_flags[2] != true)
			var->stored_flags[2] = (*var->format == '0') ? true : false;
		if (var->stored_flags[3] != true)
			var->stored_flags[3] = (*var->format == '-') ? true : false;
		if (var->stored_flags[4] != true)
			var->stored_flags[4] = (*var->format == '+') ? true : false;
		if (var->stored_flags[5] != true)
			var->stored_flags[5] = (*var->format == ' ') ? true : false;
		var->format++;
		return ;
	}
	else
		ft_width_and_precision(var);
}

void	ft_prepare_structure(t_var *var)
{
	var->u_val.p = NULL;
	var->type = 13;
	var->len = 6;
	var->stored_flags[0] = false;
	var->stored_flags[1] = false;
	var->stored_flags[2] = false;
	var->stored_flags[3] = false;
	var->stored_flags[4] = false;
	var->stored_flags[5] = false;
	var->stored_flags[6] = false;
	var->width = 0;
	var->precision = -1;
	var->prefix = NULL;
	var->stem = NULL;
	var->suffix = NULL;
	return ;
}

void	ft_clean_structure(t_var *var)
{
	if (var->type == 10 && var->u_val.str)
		ft_strdel(&var->u_val.str);
	if (var->prefix != NULL)
		ft_strdel(&var->prefix);
	if (var->stem != NULL)
		ft_strdel(&var->stem);
	if (var->suffix != NULL)
		ft_strdel(&var->suffix);
	ft_prepare_structure(var);
	return ;
}

int		ft_print_buffer(char *buff, int *b_counter, t_var *var)
{
	int		i;

	i = ft_strlen(buff);
	ft_putstr_fd(buff, var->fd);
	ft_memset(buff, '\0', BUFF_SIZE_PRINTF + 1);
	*b_counter = 0;
	return (i);
}

int		ft_print_eol(t_var *var)
{
	int		i;

	if (var->prefix)
		ft_putstr_fd(var->prefix, var->fd);
	write(var->fd, "\0", 1);
	if (var->suffix)
		ft_putstr_fd(var->prefix, var->fd);
	i = ft_strlen(var->suffix) + ft_strlen(var->stem)
		+ ft_strlen(var->prefix) + 1;
	return (i);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 11:09:11 by dwald             #+#    #+#             */
/*   Updated: 2017/10/19 16:02:58 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_dprintf.h"

static	void	ft_var_sort(t_var *var, va_list *ap)
{
	while (ft_strchr("#0+- .1234567890", *var->format))
		ft_sort_flags(var);
	ft_len(var);
	if (*var->format == '%')
		ft_pct_arg(var);
	else
		ft_sort_argument_type(var, ap);
	var->format++;
	return ;
}

static	void	ft_apply_flags(t_var *var)
{
	const	t_flag	t_flags[] = {
		{ true, ft_precision },
		{ true, ft_hash_flag },
		{ true, ft_zero_flag },
		{ true, ft_minus_flag },
		{ true, ft_plus_flag },
		{ true, ft_space_flag },
		{ true, ft_space_padding },
		{ false, NULL }
	};
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (t_flags[j].flag != false)
	{
		if (t_flags[j].flag == var->stored_flags[i++])
			(t_flags[j].flag_ptr)(var);
		j++;
	}
}

static int		ft_concatenate(t_var *var)
{
	if (var->type == 8 && ((var->stem) == '\0'))
		return (ft_print_eol(var));
	if (var->stem != NULL && var->prefix != NULL)
		var->stem = ft_strjoinfree(var->prefix, var->stem, 2);
	else if (var->stem == NULL && var->prefix != NULL)
		var->stem = ft_strdup(var->prefix);
	if (var->suffix != NULL)
	{
		if (var->stem != NULL)
			var->stem = ft_strjoinfree(var->stem, var->suffix, 1);
		else
			var->stem = ft_strdup(var->suffix);
	}
	ft_putstr_fd(var->stem, var->fd);
	return (ft_strlen(var->stem));
}

static	void	ft_output(t_var *var, char *buff, va_list *ap, int *i)
{
	int		buff_counter;

	buff_counter = 0;
	while (*var->format && var->format)
	{
		if (*var->format == '%')
		{
			*i += ft_print_buffer(buff, &buff_counter, var);
			if (!(*(++var->format)))
				return ;
			ft_var_sort(var, ap);
			ft_apply_flags(var);
			*i += ft_concatenate(var);
			ft_clean_structure(var);
			return ;
		}
		else
		{
			if (buff_counter >= BUFF_SIZE_PRINTF)
				*i += ft_print_buffer(buff, &buff_counter, var);
			buff[buff_counter++] = *var->format;
			var->format++;
		}
	}
	return ;
}

int				ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	char	buff[BUFF_SIZE_PRINTF + 1];
	int		i;
	t_var	var;

	var.format = (char *)format;
	var.fd = fd;
	va_start(ap, format);
	ft_prepare_structure(&var);
	ft_memset(buff, '\0', BUFF_SIZE_PRINTF + 1);
	i = 0;
	if (!var.format)
		return (-1);
	while (*var.format)
		ft_output(&var, buff, &ap, &i);
	if (!*var.format && ft_strlen(buff) != 0)
	{
		i += ft_strlen(buff);
		ft_putstr_fd(buff, fd);
	}
	va_end(ap);
	return (i);
}

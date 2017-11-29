/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dprintf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/22 13:48:32 by dwald             #+#    #+#             */
/*   Updated: 2017/10/20 13:29:16 by dwald            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DPRINTF_H
# define FT_DPRINTF_H

/*
** --------------------------- Librairies --------------------------------------
*/

# include "libft.h"
# include <stdarg.h>
# include <stdbool.h>
# include <limits.h>

# define BUFF_SIZE_PRINTF 10

/*
** --------------------------- colors related defines --------------------------
*/

# define PF_RED			"\033[31m"
# define PF_GREEN		"\033[32m"
# define PF_YELLOW		"\033[33m"
# define PF_BLUE		"\033[34m"
# define PF_MAGENTA		"\033[35m"
# define PF_CYAN		"\033[36m"
# define PF_HIGHLIGHT	"\033[1m"
# define PF_UNDERLINE	"\033[4m"
# define PF_BLINK		"\033[5m"
# define PF_EOC			"\033[0m"

/*
** --------------------------- ft_printf_fd variables --------------------------
** A) Printf writes the output and then returns the len (int)
** E) printed is the temporary len of chars to be send to the buffer
** F) fd is the file descriptor.
*/

typedef struct			s_var
{
	union
	{
		long long		nbr;
		char			*str;
		void			*p;
	}					u_val;
	int					type;
	int					len;
	bool				stored_flags[7];
	int					width;
	int					precision;
	char				*stem;
	char				*prefix;
	char				*suffix;
	char				*format;
	int					fd;
}						t_var;

/*
** ------------------------------ type specifier -------------------------------
** spec_di = 0  spec_D(ld) = 1  spec_u = 2  spec_U(lu) = 3  spec_o = 4
** spec_O(lo) = 5   spec_x = 6  spec_X = 7  spec_c = 8  spec_C(lc) = 9
** spec_s = 10  spec_S = 11 spec_p = 12 no_spec = 13
*/

enum					e_type
{
	spec_di,
	spec_D,
	spec_u,
	spec_U,
	spec_o,
	spec_O,
	spec_x,
	spec_X,
	spec_c,
	spec_C,
	spec_s,
	spec_S,
	spec_p,
	no_spec,
};

/*
** ----------------------------- length specifier ------------------------------
** len_hh = 0   len_h = 1   len_l = 2   len_ll = 3  len_j = 4   len_z = 5
*/

enum					e_len
{
	len_hh,
	len_h,
	len_l,
	len_ll,
	len_j,
	len_z,
};

/*
** ------------- structures for table of pointers to functions -----------------
*/

typedef struct			s_conv
{
	const char			arg[9];
	void				(*fptr)(va_list *ap, t_var *variable);
}						t_conv;

typedef struct			s_cast
{
	const int			length;
	void				(*cast_ptr)(t_var *var, va_list *ap);
}						t_cast;

typedef struct			s_flags
{
	const bool			flag;
	void				(*flag_ptr)(t_var *var);
}						t_flag;

/*
** --------------------------- ft_dprintf main functions ---------------------
*/

int						ft_dprintf(int fd, const char *format, ...);
int						ft_print_eol(t_var *variable);
int						ft_print_buffer(char *buff, int *b_counter, t_var *var);
void					ft_sort_argument_type(t_var *var, va_list *ap);

/*
** --------------------------- argument atribution functions -------------------
*/

void					ft_int_arg(va_list *ap, t_var *variable);
void					ft_long_arg(va_list *ap, t_var *variable);
void					ft_char_arg(va_list *ap, t_var *variable);
void					ft_ptr_arg(va_list *ap, t_var *variable);
void					ft_pct_arg(t_var *variable);

/*
** --------------------------- conversion functions ---------------------------
*/

void					ft_len(t_var *variable);
void					ft_width_and_precision(t_var *variable);
void					ft_sort_flags(t_var *variable);
void					ft_cast_char(t_var *var, va_list *ap);
void					ft_cast_short(t_var *var, va_list *ap);
void					ft_cast_long(t_var *var, va_list *ap);
void					ft_cast_longlong(t_var *var, va_list *ap);
void					ft_cast_size_t(t_var *var, va_list *ap);
void					ft_cast_intmax_t(t_var *var, va_list *ap);
void					ft_no_cast(t_var *var, va_list *ap);

/*
** --------------------------- ft_dprintf flags functions --------------------
*/

void					ft_hash_flag(t_var *variable);
void					ft_zero_flag(t_var *variable);
void					ft_minus_flag(t_var *variable);
void					ft_plus_flag(t_var *variable);
void					ft_space_flag(t_var *var);
void					ft_space_padding(t_var *var);
void					ft_precision(t_var *variable);
int						ft_padding_length(t_var *variable);

/*
** --------------------------- miscellaneous functions -------------------------
*/

void					ft_clean_structure(t_var *varibale);
void					ft_prepare_structure(t_var *varibale);

#endif

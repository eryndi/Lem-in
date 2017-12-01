/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dwald <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/17 12:11:36 by dwald             #+#    #+#             */
/*   Updated: 2017/12/01 19:35:25 by dhadley          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*
** --------------------------- Librairies --------------------------------------
*/

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>
# include "../srcs/ft_dprintf/includes/ft_dprintf.h"

# define BUFF_SIZE	1024

/*
** ----------------- general structure for chained lists -----------------------
*/

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

/*
** --------------------------- write functions ---------------------------------
*/

void				ft_putchar(char c);
void				ft_myputchar(char *string, char c);
void				ft_putstr(char const *s);
void				ft_myputstr(char const *s1, char const *s2);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr(int n);
void				ft_putnbrn(long long int n);
void				ft_putnbr_base(long long int n, unsigned int base);
void				ft_putnbr_fd(int n, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putendl(char const *s);
void				ft_myputnbr(char *str, int n);
void				ft_myputendl(char const *s1, char const *s2);

/*
** --------------------------- cleaning functions ------------------------------
*/

void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *b, int c, size_t len);
void				ft_strdel(char **as);
void				ft_strclr(char *s);

/*
** ---------------------------- mem functions ----------------------------------
*/

void				*ft_memalloc(size_t size);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *s1, const void *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
void				*ft_memdup(const void *s, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				ft_memdel(void **ap);
void				ft_protect_malloc(void);

/*
** -------------------------- string manipulation -----------------------------
*/

size_t				ft_strlen(char const *s);
char				*ft_strnew(size_t size);
char				*ft_strnewset(int c, size_t len);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strjoinfree(char *s1, char *s2, int free_malloc);
char				*ft_strtrim(char const *s);
int					ft_countdigits(int n);
char				*ft_strdup(char const *s1);
char				*ft_strndup(char const *s1, int n);
char				*ft_strdupfree(char *s1, int free_malloc);
char				*ft_strndupfree(char *s1, int n, int free_malloc);
char				*ft_strrev(char *s);
char				*ft_strmemrev(const char *s);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *little, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					get_next_line(const int fd, char **line);

/*
** ------------------------------ string parsing -------------------------------
*/

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_iswhitespaces(int c);
char				**ft_strsplit(char const *s, char c);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);

/*
** -------------------------- conversion functions -----------------------------
*/

int					ft_atoi(const char *str);
char				*ft_itoa(int n);
char				*ft_itoa_base(long long int value, int base);
char				*ft_itoa_base_ull(unsigned long long int value, int base);
char				*ft_itoa_base_upper(long long int value, int base);
char				*ft_itoa_base_upper_ull(unsigned long long value, int base);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				ft_swap(int *a, int *b);

/*
** ---------------------- linked lists manipulation ---------------------------
*/

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

/*
** ---------------------- added by dhadley for lem_in -------------------------
*/

t_list				*ft_list_new_elem(void *content);
t_list				*ft_list_find_end(t_list *list);
void				ft_list_push_start(t_list **begin_list, void *content);
void				ft_list_push_end(t_list **begin_list, void *content);

#endif

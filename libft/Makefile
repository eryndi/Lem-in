# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwald <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/05 13:52:24 by dwald             #+#    #+#              #
#    Updated: 2017/12/02 17:37:01 by dhadley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= 		libft.a

SRC_FILES	=	ft_atoi.c \
				ft_bzero.c \
				ft_countdigits.c \
				ft_isalnum.c \
				ft_isalpha.c \
				ft_isascii.c \
				ft_isdigit.c \
				ft_isprint.c \
				ft_iswhitespaces.c \
				ft_itoa.c \
				ft_itoa_base.c \
				ft_itoa_base_ull.c \
				ft_itoa_base_upper.c \
				ft_itoa_base_upper_ull.c \
				ft_lstadd.c \
				ft_lstdel.c \
				ft_lstdelone.c \
				ft_lstiter.c \
				ft_lstmap.c \
				ft_lstnew.c \
				ft_memalloc.c \
				ft_memccpy.c \
				ft_memchr.c \
				ft_memcmp.c \
				ft_memcpy.c \
				ft_memdel.c \
				ft_memdup.c \
				ft_memmove.c \
				ft_memset.c \
				ft_myputchar.c \
				ft_myputendl.c \
				ft_myputnbr.c \
				ft_myputstr.c \
				ft_protect_malloc.c \
				ft_putchar.c \
				ft_putchar_fd.c \
				ft_putendl.c \
				ft_putendl_fd.c \
				ft_putnbr.c \
				ft_putnbrn.c \
				ft_putnbr_base.c \
				ft_putnbr_fd.c \
				ft_putstr.c \
				ft_putstr_fd.c \
				ft_strcat.c \
				ft_strchr.c \
				ft_strclr.c \
				ft_strcmp.c \
				ft_strcpy.c \
				ft_strdel.c \
				ft_strdup.c \
				ft_strdupfree.c \
				ft_strequ.c \
				ft_striter.c \
				ft_striteri.c \
				ft_strjoin.c \
				ft_strjoinfree.c \
				ft_strlcat.c \
				ft_strlen.c \
				ft_strmap.c \
				ft_strmapi.c \
				ft_strmemrev.c \
				ft_strncat.c \
				ft_strncmp.c \
				ft_strncpy.c \
				ft_strndup.c \
				ft_strndupfree.c \
				ft_strnequ.c \
				ft_strnew.c \
				ft_strnewset.c \
				ft_strnstr.c \
				ft_strrchr.c \
				ft_strrev.c \
				ft_strsplit.c \
				ft_strstr.c \
				ft_strsub.c \
				ft_strtrim.c \
				ft_swap.c \
				ft_tolower.c \
				ft_toupper.c \
				get_next_line.c \
				ft_dprintf/srcs/args_part_1.c \
				ft_dprintf/srcs/args_part_2.c \
				ft_dprintf/srcs/args_part_3.c \
				ft_dprintf/srcs/auxiliary_functions.c \
				ft_dprintf/srcs/flags.c \
				ft_dprintf/srcs/ft_dprintf.c \
				ft_dprintf/srcs/length_part_1.c \
				ft_dprintf/srcs/length_part_2.c \
				ft_dprintf/srcs/width_and_precision.c \
				ft_list_find_end.c \
				ft_list_new_elem.c \
				ft_list_push_end.c \
				ft_list_push_start.c \

SRC_PATH	=	srcs

OBJ_PATH	=	objs

SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_FILES))

OBJ			=	$(addprefix $(OBJ_PATH)/,$(SRC_FILES:.c=.o))

INC			=	includes

INC_FT_DPRINTF = srcs/ft_dprintf/includes

CC			=	gcc

FLAGS		=	-Wall -Wextra -Werror -O3

GREEN		=	\033[92m
RED			=	\033[0;31m
NC			=	\033[0m

all		: 	$(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
			@mkdir -p $(OBJ_PATH)
			@mkdir -p $(OBJ_PATH)/ft_dprintf/srcs
			@$(CC) $(FLAGS) -I $(INC) -I $(INC_FT_DPRINTF) -o $@ -c $<
			@printf "                                             \r"
			@printf "✅  $(notdir $<)\r"

$(NAME)	:	$(OBJ)
			@ar rc $(NAME) $(OBJ)
			@ranlib $(NAME)
			@echo "$(GREEN)Success : $(NC)libft.a compiled"

clean	:
				@/bin/rm -f $(OBJ)
				@echo "$(RED)---libft all objects removed----$(NC)"

fclean	: 		clean
				/bin/rm -f $(NAME)
				@echo "$(RED)---libft removed completely----$(NC)"

re		:		fclean all

ree		:		re
				rm -f $(OBJ)

.PHONY: all clean fclean re ree

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwald <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 14:50:39 by dwald             #+#    #+#              #
#    Updated: 2017/11/29 16:02:07 by dwald            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	lem-in

SRC_FILES	=
				main.c \

SRC_PATH	=	src

OBJ_PATH	=	objs

LIBFT_PATH	= 	libft

SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_FILES))

OBJ			=	$(addprefix $(OBJ_PATH)/,$(SRC_FILES:.c=.o))

LIBFT		=	$(addprefix $(LIBFT_PATH)/,$(LIBFTA))

INC			=	includes

LIBFTA		=	libft.a

CC			=	gcc

FLAGS		=	#-Wextra -Werror -Wall

GREEN =         \033[0;32m
WHITE =			\x1B[37m
RED =           \033[0;31m
NC =            \033[0m

all:			$(NAME)

$(NAME):		$(OBJ)
				@make -C $(LIBFT_PATH)
				@$(CC) $(FLAGS) $(LIBFT) -I.libft/includes - o $(NAME)
				@echo "$(GREEN)exe lem-in compiled$(NC)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
				@mkdir -p $(OBJ_PATH)
				@printf "$(WHITE)🐜  notdir $<)\r"


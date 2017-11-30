# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwald <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 14:50:39 by dwald             #+#    #+#              #
#    Updated: 2017/11/30 11:04:30 by dwald            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	lem-in

SRC_FILES	=	main.c \

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

GREEN		=   \033[92m
RED			=	\033[0;31m
BG_WHITE	=	\033[47m
NC			=	\033[0m

all:			$(NAME)

$(NAME):		$(OBJ)
				@make -C $(LIBFT_PATH)
				@$(CC) $(FLAGS) $(OBJ) $(LIBFT) -I./libft/includes -o $(NAME)
				@echo "$(GREEN)exe lem-in compiled$(NC)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
				@mkdir -p $(OBJ_PATH)
				@printf "                                                   \r"
				@printf "$(BG_WHITE)🐜 $(NC) $(notdir $<)\r"
				@$(CC) $(FLAGS) -I $(INC) -I./libft/includes -o $@ -c $<

clean:
				/bin/rm -f $(OBJ)
				make fclean -C $(LIBFT_PATH)

fclean:			clean
				/bin/rm -f $(NAME)
				@echo "$(RED)---dwald.filler removed completely---$(NC)"

re:				fclean all

norme:
				normeinette $(SRC)
				normeinette $(INC_PATH)*.h

.PHONY:			all fclean clean re norme

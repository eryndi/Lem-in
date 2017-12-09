# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dwald <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/29 14:50:39 by dwald             #+#    #+#              #
#    Updated: 2017/12/09 19:25:43 by dhadley          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	lem-in

SRC_FILES	=	main.c \
				lem-in_auxiliary_functions.c \
				algo.c \
				init.c \
				parse.c \
				parse_rooms.c \
				parse_tubes.c \
				make_connections.c \

SRC_PATH	=	src

OBJ_PATH	=	objs

LIBFT_PATH	= 	libft

SRC			=	$(addprefix $(SRC_PATH)/,$(SRC_FILES))

OBJ			=	$(addprefix $(OBJ_PATH)/,$(SRC_FILES:.c=.o))

LIBFT		=	$(addprefix $(LIBFT_PATH)/,$(LIBFTA))

LIBFT_INC	=	$(addprefix $(LIBFT_PATH)/,$(INC))

INC			=	includes

LIBFTA		=	libft.a

CC			=	gcc

FLAGS		=	#-Wextra -Werror -Wall

GREEN		=   \033[92m
BLACK		=   \033[30m
RED			=	\033[0;31m
BG_WHITE	=	\033[47m
NC			=	\033[0m

all:			$(NAME)

$(NAME):		$(OBJ)
				@make -C $(LIBFT_PATH)
				@$(CC) $(FLAGS) $(OBJ) $(LIBFT) -I $(LIBFT_INC) -o $(NAME)
				@echo "$(BG_WHITE) 🐜 🐜 🐜 🐜 $(BLACK) lem-in compiled $(NC)\
$(BG_WHITE)🐜 🐜 🐜 🐜  $(NC)"

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
				@mkdir -p $(OBJ_PATH)
				@printf "                                                   \r"
				@printf "$(BG_WHITE)🐜  $(NC) $(notdir $<)\r"
				@$(CC) $(FLAGS) -I $(INC) -I $(LIBFT_INC) -o $@ -c $<

clean:
				/bin/rm -f $(OBJ)
				make clean -C $(LIBFT_PATH)
				@echo "$(RED)---lem-in all objects removed---$(NC)"

fclean:			clean
				/bin/rm -f $(NAME)
#				make fclean -C $(LIBFT_PATH)
				@echo "$(RED)---lem-in removed completely---$(NC)"

re:				fclean all

norme:
				normeinette $(SRC)
				normeinette $(INC_PATH)*.h

.PHONY:			all fclean clean re norme

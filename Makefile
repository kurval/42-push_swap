# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 10:06:21 by vkurkela          #+#    #+#              #
#    Updated: 2020/04/19 18:11:12 by vkurkela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap
NAME2 = checker

SRC1 = push_swap_files/push_swap.c push_swap_files/sort_stack.c \
		push_swap_files/sort_three.c push_swap_files/sort_five.c \
		push_swap_files/big_sort.c push_swap_files/shortest_way.c

SRC2 = checker_files/checker.c checker_files/read_instructions.c \
		checker_files/execute_rules.c checker_files/check_rules.c \

OBJ = *.o

GREEN = \033[1;32m
RED = \033[1;31m
YEL = \033[1;33m
WHT = \033[1;37m
EOC = \033[1;0m

HEADERS1 = includes/push_swap.h
HEADERS2 = includes/checker.h

LIBFT = libft/libft.a
LIB = lib/lib.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME1)

$(NAME1):
	@echo "$(WHT)Compiling libraries...$(EOC)"
	@${MAKE} -C libft
	@${MAKE} -C lib
	@echo "$(GREEN)Libraries done.$(EOC)"

	@echo "$(WHT)Compiling push_swap...$(EOC)"
	@$(CC) $(FLAGS) -c $(SRC1) -I$(HEADERS1)
	@$(CC) $(FLAGS) -o $(NAME1) $(OBJ) $(LIBFT) $(LIB)
	@mkdir obj
	@mv $(OBJ) ./obj
	@echo "$(GREEN)push_swap build completed.$(EOC)"

	@echo "$(WHT)Compiling checker...$(EOC)"
	@$(CC) $(FLAGS) -c $(SRC2) -I$(HEADERS2)
	@$(CC) $(FLAGS) -o $(NAME2) $(OBJ) $(LIBFT) $(LIB)
	@mv $(OBJ) ./obj
	@echo "$(GREEN)checker build completed.$(EOC)"
	
clean:
	@echo "$(WHT)Removing o-files...$(EOC)"
	@/bin/rm -f $(OBJ)
	@/bin/rm -Rf obj
	@${MAKE} -C libft clean
	@${MAKE} -C lib clean
	@echo "$(GREEN)Clean done.$(EOC)"

fclean: clean
	@echo "$(WHT)Removing object- and binary -files...$(EOC)"
	@/bin/rm -f $(NAME1) $(NAME2)
	@${MAKE} -C libft fclean
	@${MAKE} -C lib fclean
	@echo "$(GREEN)Fclean done.$(EOC)"

re: fclean all

.PHONY: all clean fclean re

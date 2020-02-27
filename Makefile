# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 10:06:21 by vkurkela          #+#    #+#              #
#    Updated: 2020/02/27 10:47:18 by vkurkela         ###   ########.fr        #
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

HEADERS1 = includes/push_swap.h
HEADERS2 = includes/checker.h

LIBFT = libft/libft.a
LIB = lib/lib.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

all: $(NAME1)

$(NAME1):
	@${MAKE} -C libft
	@${MAKE} -C lib
	$(CC) $(FLAGS) -c $(SRC1) -I$(HEADERS1)
	$(CC) $(FLAGS) -o $(NAME1) $(OBJ) $(LIBFT) $(LIB)
	mkdir obj
	mv $(OBJ) ./obj

	$(CC) $(FLAGS) -c $(SRC2) -I$(HEADERS2)
	$(CC) $(FLAGS) -o $(NAME2) $(OBJ) $(LIBFT) $(LIB)
	mv $(OBJ) ./obj
	
clean:
	/bin/rm -f $(OBJ)
	/bin/rm -Rf obj
	@${MAKE} -C libft clean
	@${MAKE} -C lib clean

fclean: clean
	/bin/rm -f $(NAME1) $(NAME2)
	@${MAKE} -C libft fclean
	@${MAKE} -C lib fclean

re: fclean all

.PHONY: all clean fclean re

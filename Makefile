# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 10:06:21 by vkurkela          #+#    #+#              #
#    Updated: 2020/02/12 17:11:28 by vkurkela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap

SRC1 = push_swap_files/push_swap.c push_swap_files/moves.c \
		push_swap_files/sort_stack.c

OBJ = *.o

HEADERS = includes/push_swap.h

LIBFT = libft/libft.a
LIB = lib/lib.a

CC = gcc

FLAGS = -Wall -Wextra -Werror -I$(HEADERS)

all: $(NAME1)

$(NAME1):
	@${MAKE} -C libft
	@${MAKE} -C lib
	$(CC) $(FLAGS) -c $(SRC1)
	$(CC) $(FLAGS) -o $(NAME1) $(OBJ) $(LIBFT) $(LIB)
	mkdir obj
	mv $(OBJ) ./obj
	
clean:
	/bin/rm -Rf obj
	@${MAKE} -C libft clean
	@${MAKE} -C lib clean

fclean: clean
	/bin/rm -f $(NAME1)
	@${MAKE} -C libft fclean
	@${MAKE} -C lib fclean

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/10 10:06:21 by vkurkela          #+#    #+#              #
#    Updated: 2020/02/10 15:26:05 by vkurkela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = push_swap

SRC1 = push_swap_files/main.c push_swap_files/error_check.c \
		push_swap_files/helper_functions.c

OBJ = *.o

HEADERS = includes/push_swap.h

LIBFT = libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror -I$(HEADERS)

all: $(NAME1)

$(NAME1):
	@${MAKE} -C libft
	$(CC) $(FLAGS) -c $(SRC1)
	$(CC) $(FLAGS) -o $(NAME1) $(OBJ) $(LIBFT)
	mkdir obj
	mv $(OBJ) ./obj
	
clean:
	/bin/rm -Rf obj
	@${MAKE} -C libft clean

fclean: clean
	/bin/rm -f $(NAME1)
	@${MAKE} -C libft fclean

re: fclean all

.PHONY: all clean fclean re

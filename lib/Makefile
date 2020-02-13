# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 16:57:02 by vkurkela          #+#    #+#              #
#    Updated: 2020/02/13 21:06:07 by vkurkela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib.a

SRC = error_check.c free_stack.c free_stack.c \
	push.c print_stack.c new_node.c is_empty.c \
	del_node.c

HEADERS = lib.h

OBJECTS = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror -I$(HEADERS)

CC = gcc

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJECTS)

clean:
	/bin/rm -f $(OBJECTS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkurkela <vkurkela@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 16:57:02 by vkurkela          #+#    #+#              #
#    Updated: 2020/02/27 10:48:52 by vkurkela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib.a

SRC = error_check.c push.c print_stack.c check_rev_order.c \
	rotate.c swap.c rev_rotate.c swap.c sort_tab.c \
	helper_functions.c rules.c check_order.c check_flag.c \

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
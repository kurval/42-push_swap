# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/12 16:57:02 by vkurkela          #+#    #+#              #
#    Updated: 2020/02/12 17:02:03 by vkurkela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lib.a

SRC = error_check.c helper_functions.c

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
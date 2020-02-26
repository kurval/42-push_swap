# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkurkela <vkurkela@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/07 12:00:29 by vkurkela          #+#    #+#              #
#    Updated: 2020/02/26 23:59:03 by vkurkela         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ./src/ft_printf.c ./src/parser.c ./src/type_f.c ./src/type_c.c \
	./src/type_p.c ./src/flag_percent.c ./src/parse_length.c ./src/width.c \
	./src/precision.c ./src/type_id.c ./src/type_o.c ./src/type_u.c\
	./src/type_x.c ./src/type_s.c ./src/typecast.c ./src/type_a.c ./src/type_n.c

OBJ = *.o

HEADERS = includes/printf.h

CC = gcc

FLAGS = -Wall -Wextra -Werror -I$(HEADERS)

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJ)
	mkdir obj
	mv $(OBJ) ./obj
	
clean:
	/bin/rm -Rf obj

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qgirard <qgirard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/01 04:08:24 by qgirard           #+#    #+#              #
#    Updated: 2019/08/02 05:14:19 by qgirard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

EXEC = lem-in

COMPILIB = make -C include/libft
CLIB = make -C include/libft clean
FCLIB = make -C include/libft fclean
LIB = include/libft/libft.a

HEADER = include/lemin.h

CC = gcc -o
CFLAGS = -g -Wall -Wextra -Werror
#-g3 -fsanitize=address

SRC = srcs/main.c srcs/checklines.c srcs/fill_lists.c srcs/check_map_validity.c \
		srcs/free_lists.c srcs/error.c

OBJ = $(SRC:.c=.o)

all : $(LIB) $(EXEC)

$(LIB) :
	$(COMPILIB)

$(EXEC) : $(OBJ)
	$(CC) $(EXEC) $(CFLAGS) $(SRC) $(LIB)

%.o: %.c
	@$(CC) $(CFLAGS) -c -I $(HEADER) $< -o $@

clean :
	rm -rf $(OBJ)
	$(CLIB)

fclean : clean
	rm -rf $(EXEC)
	$(FCLIB)

re : fclean all

.PHONY : all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykliek <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/13 13:47:37 by ykliek            #+#    #+#              #
#    Updated: 2019/10/02 15:11:37 by ykliek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Werror -Wextra

LIB = libft/libft.a

SRCS = lem_in.c \
		reader.c \
		error_management.c \
		parser.c \
		dblst_tools.c \
		bfs.c \
		go_ants.c \
		room.c \
		tools.c

OBJ = lem-in.o

INCLUDE = lem_in.h

all: $(NAME)

$(NAME):
	@make -C libft
	@gcc $(SRCS) $(LIB) -o $(NAME)

clean:
	@rm -rf $(OBJ)
	@make -C libft clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft fclean

re: fclean all

cleanlib:
	make -C libft clean

fcleanlib:
	make -C libft fclean

relib:
	make -C libft re

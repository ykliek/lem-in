# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ykliek <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/13 13:47:37 by ykliek            #+#    #+#              #
#    Updated: 2019/08/13 13:47:39 by ykliek           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

FLAGS = -Wall -Werror -Wextra

LIB = libft/libft.a

SRCS = main.c \
		lst_tools.c \
		reader.c \
		validator.c \
		error_management.c

INCLUDE = lem-in.h

all: $(NAME)

$(NAME):
	@make -C libft
	clang $(FLAGS) $(SRCS) $(LIB) -o $(NAME)

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

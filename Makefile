# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/23 15:33:03 by ahua              #+#    #+#              #
#    Updated: 2015/02/11 15:16:50 by ahua             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = test.c \
	  get_next_line.c

LIB	= libft/libft.a

OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -L/usr/X11/lib -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ re
	@$(CC) -o $(NAME) $(OBJ) $(FLAGS) -I. $(LIB) -g

%.o: %.c
	@$(CC) -c -o $@ $(FLAGS) $^ -g

.PHONY : clean fclean re

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean $(NAME)

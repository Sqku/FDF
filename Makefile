# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahua <ahua@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/23 15:33:03 by ahua              #+#    #+#              #
#    Updated: 2015/03/03 21:30:53 by ahua             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
SRC = main.c \
	  get_next_line.c \
	  get_map.c \
	  line.c \
	  color.c \
	  draw.c \
	  key_hook.c \
	  init.c

LIB	= libft/libft.a

OBJ = $(SRC:.c=.o)
CC = gcc
FLAGS = -Wall -Wextra -Werror 

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/ re
	@$(CC) -o $(NAME) $(OBJ) $(FLAGS) -I. $(LIB) -I minilibx_macos -lmlx -framework OpenGL -framework AppKit

%.o: %.c
	@$(CC) -c -o $@ $(FLAGS) $^

.PHONY : clean fclean re

clean:
	@rm -f $(OBJ)
	@make -C libft/ clean

fclean: clean
	@rm -f $(NAME)
	@make -C libft/ fclean

re: fclean $(NAME)

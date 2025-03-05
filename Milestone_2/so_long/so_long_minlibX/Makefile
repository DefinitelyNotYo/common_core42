# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 18:43:58 by yoherfan          #+#    #+#              #
#    Updated: 2025/03/04 14:59:22 by yoherfan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRC = so_long.c so_long_clean.c so_long_images.c so_long_map.c get_next_line.c \
		get_next_line_utils.c so_long_parsing.c so_long_utils.c \
		so_long_mov.c so_long_character.c so_long_floodfill.c

OBJ = $(SRC:.c=.o)

ARCHIVE = -Lminilibx-linux -lmlx -lXext -lX11

all: $(NAME)

$(NAME): $(OBJ)
	make -C minilibx-linux
	$(CC) $(OBJ) $(ARCHIVE) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	make clean -C minilibx-linux

re: fclean all

.PHONY: all clean fclean re


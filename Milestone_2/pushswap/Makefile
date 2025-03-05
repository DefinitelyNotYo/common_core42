# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 18:43:58 by yoherfan          #+#    #+#              #
#    Updated: 2025/02/11 16:02:08 by yoherfan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRC = pushswap.c pushswap_utils.c pushswap_stack.c pushswap_moves.c \
		pushswap_parsing.c pushswap_string_handle.c pushswap_sorting.c \
		pushswap_moves2.c pushswap_foreplay.c pushswap_same_sign.c \
		pushswap_updater.c pushswap_utils2.c pushswap_discrd_sign.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re


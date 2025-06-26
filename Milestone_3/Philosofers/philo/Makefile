# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/25 14:35:52 by yoherfan          #+#    #+#              #
#    Updated: 2025/06/26 16:46:06 by yoherfan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosofers

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -pthread

SRC = actions.c clean.c messages.c parsing.c philosofers.c setup.c utils.c \
	wrap.c

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

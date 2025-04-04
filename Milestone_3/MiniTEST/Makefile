# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/16 18:43:58 by yoherfan          #+#    #+#              #
#    Updated: 2025/04/03 16:24:32 by yoherfan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

NAMEB = pipex_bonus

CC = cc

CFLAGS = -Wall -Wextra -g -lreadline -lhistory

SRC = get_next_line_utils.c get_next_line.c \
	  pipex_clean.c pipex_manager.c pipex.c pipex_split.c pipex_utils.c

SRC_BONUS = get_next_line_utils_bonus.c get_next_line_bonus.c \
			pipex_clean_bonus.c pipex_manager_bonus.c pipex_bonus.c \
			pipex_split_bonus.c pipex_utils_bonus.c pipex_heredoc_bonus.c \
			testingAREA.c

OBJ = $(SRC:.c=.o)

OBJ_BONUS = $(SRC_BONUS:.c=.o)

all: $(NAME)

bonus: $(NAMEB)

$(NAMEB): $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAMEB)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)
	rm -f $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAMEB)
re: fclean all

.PHONY: all clean fclean re bonus


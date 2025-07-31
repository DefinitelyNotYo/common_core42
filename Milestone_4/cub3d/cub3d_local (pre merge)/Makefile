# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/18 16:04:07 by cciapett          #+#    #+#              #
#    Updated: 2025/07/31 16:55:47 by yoherfan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3d

CC = cc

LIB = -Lminilibx-linux_cub3d -lmlx -lXext -lX11 -lm -Llibft -l:libft.a

CFLAGS = -Wall -Werror -Wextra -g -Iminilibx-linux -Ilibft 

SRCS = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c \
parsing/check_direction.c parsing/input_file.c parsing/inspect.c \
parsing/line.c parsing/messages.c \
parsing/parsing_map.c parsing/parsing_utils.c parsing/parsing.c \
main.c read_map.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	make -C minilibx-linux_cub3d
	$(CC) $(CFLAGS) $(OBJS) $(LIB) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re: fclean all

.PHONY: all clean fclean re
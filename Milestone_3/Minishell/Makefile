# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/04 16:05:29 by yoherfan          #+#    #+#              #
#    Updated: 2025/06/17 17:42:38 by yoherfan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror -g -Ilibft

SRC = free_str.c main_setup.c minishell.c prompt.c cd.c env.c env_utils.c\
 pwd.c copy_env.c echo.c arguments.c quotes.c clean.c dollar.c \
 dollar_utils.c dollar_utils2.c dollar_utils3.c dollar_doc.c cd_utils.c cd_error.c export.c \
 export_utils.c export_utils2.c export_utils3.c export_order.c exec.c manager.c built-in.c unset.c \
 exit.c pipes.c exec_manager.c redirect_out.c redirect_in.c get_next_line.c \
 get_next_line_utils.c signal.c prompt_err.c args_cleaning.c get_next_line_utils2.c manager2.c \
 redirect_in2.c redirect_out2.c redirect_fix.c main_exe.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -lreadline -lhistory -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make clean -C libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus


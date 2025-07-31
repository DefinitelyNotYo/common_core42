/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:35:50 by yoherfan          #+#    #+#             */
/*   Updated: 2025/07/21 16:43:26 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <ctype.h>
# include <fcntl.h>
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1025
# endif

char	*get_next_line(int fd);
char	*find_scrap(char *str);
char	*find_line(char *str);
char	*solve_problems(char *buffer, char **scrap);

void	*ft_calloc(size_t nmemb, size_t size);
int		check_newline(char *str);

#endif
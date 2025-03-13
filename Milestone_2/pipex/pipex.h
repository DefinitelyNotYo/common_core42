/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:31:00 by yoherfan          #+#    #+#             */
/*   Updated: 2025/03/13 16:43:34 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
# include <string.h>
# include <ctype.h>
# include <fcntl.h>

void    ft_free_matrix(char **matrix, int i);
int     ft_next_delim_index(const char *s, char c);
int	    count_words(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
int	ft_strlen(const char *s);
char            **ft_split(char const *s, char c);
char	        *ft_strjoin(char const *s1, char const *s2);
int         	ft_strncmp(const char *s1, const char *s2, size_t n);

void            ft_execute(char *cmd, char** env);
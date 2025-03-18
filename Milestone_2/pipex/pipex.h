/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:31:00 by yoherfan          #+#    #+#             */
/*   Updated: 2025/03/18 18:11:54 by yoherfan         ###   ########.fr       */
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


# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1025
# endif

char	*get_next_line(int fd);
char	*find_scrap(char *str);
char	*find_line(char *str);
char	*solve_problems(char *buffer, char **scrap);

int		ft_strlen_g(char *s);
char	*ft_strjoin_g(char *s1, char *s2);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(char *s);
int		check_newline(char *str);

void    ft_clean(int file_in, int file_out, int *fd);
void    ft_fast_clean(int file_in, int file_out);

void    ft_main_process_exe(int *fd);
void    ft_cmd_exe(int *files, int *fd, char *cmd, char **env);
void    ft_last_cmd_exe(int *files, int *fd, char *cmd, char **env);
void    ft_manager(int argc, int *files, char **argv, char **env);

void    ft_free_matrix(char **matrix, int i);
int     ft_next_delim_index(const char *s, char c);
int	    count_words(char const *s, char c);
void	*ft_calloc(size_t nmemb, size_t size);
int	    ft_strlen(const char *s);
char    **ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
int     ft_strncmp(const char *s1, const char *s2, size_t n);

void    ft_execute(char *cmd, char** env);
int     ft_check_args(int file_in, int files_out, int argc);
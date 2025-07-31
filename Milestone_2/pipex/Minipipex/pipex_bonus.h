/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:31:00 by yoherfan          #+#    #+#             */
/*   Updated: 2025/03/31 16:31:26 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <ctype.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_pathfinder
{
	char	**split_cmd;
	char	**split_paths;
	char	*path;
	char	*temp;
	int		index;
	int		i;
}	t_pathfinder;

char	*find_line(char *str);
char	*find_scrap(char *str);
char	*solve_problems(char *buffer);
char	*get_next_line(int fd);
void	ft_putstr_fd(char *s, int fd);

int		ft_strlen_g(char *s);
char	*ft_strjoin_g(char *s1, char *s2);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strdup(char *s);
int		check_newline(char *str);

void	ft_clean(int file_out, int *fd);
void	ft_fast_clean(int file_in, int file_out);
void	ft_free_mem(char **mat_1, char **mat_2, char *str, t_pathfinder *p);
void	ft_free_memfd(t_pathfinder *p, int *files, int toggle);
int		ft_check_n_args(int argc, char **argv);

void	ft_here_doc(int *files, char **argv, int argc);

void	ft_main_process_exe(int *fd);
void	ft_cmd_exe(int *files, int *fd, char *cmd, char **env);
void	ft_last_cmd_exe(int *files, char *cmd, char **env);
void	ft_manager(int argc, int *files, char **argv, char **env);

void	ft_free_matrix(char **matrix, int i);
int		ft_next_delim_index(const char *s, char c);
int		count_words(char const *s, char c);
char	**ft_split(char const *s, char c);
int		ft_justspaces(char *str);

int		ft_strlen(const char *s);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	ft_jolly_p(t_pathfinder *p, char *cmd);

void	ft_execute(char *cmd, char **env, int *files, int toggle);
int		ft_check_args(int file_in, int files_out, int argc, char **argv);
int		ft_check_last_exe(char *cmd, char **env, int *files);
int		ft_check_last(int argc, char **argv, char **env, int *files);

#endif
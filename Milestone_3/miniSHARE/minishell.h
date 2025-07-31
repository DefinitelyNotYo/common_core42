/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:31:00 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/23 16:08:36 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <ctype.h>
# include <fcntl.h>
# include "libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>
# include <linux/limits.h>
# include <errno.h>
# include <signal.h>
# include <termios.h>

extern int	g_var_signal;

typedef struct s_arg
{
	char	**arg;
	int		flag_out;
	int		flag_in;
}	t_arg;

typedef struct s_parameters
{
	char				*str;
	char				*prompt;
	unsigned char		dollar;
	char				*tmp;
	char				**env_copy;
	int					fd[2];
	int					n_pipes;
	t_arg				*p_args;
	char				***p_writes;
	char				***p_reads;
	int					n_total_pipes;
	int					read_0;
	int					write_1;
	int					flag_unset;
	pid_t				pid_child;
	int					herefd[2];
	int					p_len;
	int					flag_heredoc;
	char				*user;
	char				*place;
	int					lastchild;
	char				*pro_prompt;
	char				*pro_home;
	char				*pro_tmp;
	char				*pippo;
	char				*pluto;
}	t_parameters;

typedef struct s_dollar_par
{
	int		i;
	int		j;
	int		k;
	char	*s;
	char	*prv_str;
	char	*aft_str;
	char	*temp;
	int		toggle;
	char	*start;
	char	*end;
}	t_dollar_par;

typedef struct s_pathfinder
{
	char	**split_cmd;
	char	**split_paths;
	char	*path;
	char	*temp;
	int		index;
	int		i;
}	t_pathfinder;

typedef struct s_pipex
{
	char	**split_cmd;
	char	**split_paths;
	char	*path;
	char	*temp;
	int		index;
	int		i;
}	t_pipex;

//ARGS_CLEANING
void	ft_args_cleaning(t_parameters *p, int len, char **args);
void	ft_set_n_cut_redir(t_parameters *p, int len, char **args, int *i);
//ARGUMENTS.C
int		ft_next_end(const char *s, char c);
int		count_arguments(char const *s, char c);
void	set_arguments(int *param);
char	**ft_split_args(char *s, char c);
int		ft_split_args_exe(char *s, char **matrix, int *param, char c);
//FREE_STR.C
char	*ft_freejoin(char *str1, char *str2);
char	*ft_freedup(char *str1, char *str2);
//MAIN_SETUP.C
void	ft_main_setup(t_parameters *p, int argc, char **argv, char **env);
//MINISHELL.C
int		ft_faya(char *str, char *faya);
int		ft_home(char *path);
//PROMPT.C
int		env_line(char **env, char *path);
char	*ft_prompt(char **env, t_parameters *p);
void	ft_prompt_exe(t_parameters *p, char **env);
//CD.C
int		ft_strlen_matrix(char **matrix);
char	**ft_copy_matrix(char **env);
char	*ft_memcopy(char *src, int n);
char	*ft_get_env(char *str, char **env_copy);
void	ft_cd(char **matrix, char ***env_copy, t_parameters *p);
//CD_UTILS.C
int		ft_strlen_matrix(char **matrix);
char	*ft_memcopy(char *src, int n);
int		ft_strlen_3d_matrix(char ***matrix);
int		ft_strlen_arg(t_arg *matrix);
//CD_ERROR.C
void	ft_cd_home_error(char *s);
char	*ft_search_home(char **env, t_parameters *p);
void	ft_cd_error(char *matrix1, t_parameters *p);
void	ft_cd_prv_dir(char ***env_copy, int flag, char *prv_dir);
void	ft_go_to_home(char ***env_copy, char *prv_dir, t_parameters *p);
//QUOTES.C
int		get_last_quote(char *prompt);
char	*prompt_clear(char *prompt);
int		check_n_q(char *prompt, t_parameters *p);
//CLEAN.C
void	ft_free_matrix(char **matrix, int i);
void	ft_free_exec(t_pathfinder *p);
void	ft_free_3d_matrix(char ***matrix, int i);
void	ft_exec_cleaning(t_parameters *p);
void	ft_free_arg(t_parameters *p, t_arg *arg);
//COPY_ENV.C
char	**ft_copy_matrix(char **env);
//DOLLAR.C
void	ft_handle_dollar(char **matrix, t_parameters *p);
char	*ft_dollar(char *str);
char	*ft_superjoin(char *s1, char *s2);
void	ft_inner_process(t_parameters *p, t_dollar_par *par, char **matrix);
int		ft_isalnum_env(int c);
//DOLLAR_UTILS.C
char	*ft_superjoin(char *s1, char *s2);
char	*ft_dollar(char *str);
char	*ft_after_dollar(char *str);
void	ft_search_questionmark(char **str, t_parameters *p);
//DOLLAR_UTILS2.C
char	*ft_superjoin(char *s1, char *s2);
//DOLLAR_UTILS3.C
void	ft_initialize_dollar(t_dollar_par **par);
void	ft_find_env(t_dollar_par **par, char **matrix, t_parameters *p);
void	ft_not_find_env(t_dollar_par **par, char **matrix, t_parameters *p);
void	ft_prv_aft(t_dollar_par **par, char **matrix);
void	free_param(t_dollar_par **par);
//DOLLAR_DOC.C
void	ft_evaluate_toggle(char **matrix, t_dollar_par	*par);
void	ft_dollar_exe(t_dollar_par *par, char **matrix, int flag);
void	ft_call_funct_hd(t_dollar_par *par, char **matrix);
void	ft_dollar_process_hd(char **matrix, t_dollar_par *par, t_parameters *p);
void	ft_handle_dollar_doc(char **matrix, t_parameters *p);
//ECHO.C
int		ft_echo(char **matrix, t_parameters *p);
//ENV.C
void	ft_update_env(char **env_copy, char *prv_dir);
void	ft_env(char **matrix, char **env_copy, t_parameters *p);
void	ft_update_env_exe(char *dir, char **env_copy_str, int toggle);
void	ft_update_oldpwd(char **env_copy);
//ENV_UTILS.C
int		ft_condition_env(char *env_copy_str, char *str_pwd);
//EXPORT.C
int		ft_export(char **matrix, char ***env_copy, t_parameters *p);
void	ft_add_value(char ***env_copy, char *str, int pos, int *index);
//EXPORT_UTILS.C
void	ft_display_export(char **temp, char **str_copy);
void	ft_export_add_quotes(char *str);
void	ft_init_export_mtx(char ***mtx1, char ***mtx2, char ***matrix, int *i);
int		ft_check_export(char *str, t_parameters *p);
int		ft_avoid_plus(char *str);
//EXPORT_ORDER.C
int		ft_strcmp(char *s1, char *s2);
int		ft_order(char ***env_copy);
void	ft_bubble_sort(char ***env_copy);
void	ft_search_plus(char *str, char ***env_copy, int *index);
//EXPORT_UTILS2.C
void	ft_create_value_plus(char ***env_copy, char *str, int pos, int *index);
void	ft_create_value_eq(char ***env_copy, char *str, int pos, int *index);
void	ft_copy_str(char *name, char *value, char **env_copy_str);
void	ft_copy_str2(char *value, char **env_copy_str);
void	ft_substitute_value(char ***env_copy, char *str, int pos, int *index);
//EXPORT_UTILS.C
int		ft_invalid_identifier(char *str);
int		ft_isalpha_env(int c);;
//MANAGER.C
void	parse_manager(t_parameters *p);
void	clean_manager(char **args);
void	exec_manager(t_arg *args, t_parameters *p, int index);
void	parse_manager_exe(t_parameters *p, char **args);
void	ft_handle_empties(char ***matrix);
//MANAGER2.C
void	ft_parse_manager_exe_2(t_parameters *p, char **args, int len, int *i);
//EXEC.C
void	ft_execute(t_parameters *pp, char **args, char **env);
//EXIT.C
void	ft_exit(char **matrix, t_parameters *p);
//BUILT-IN.C
int		ft_is_built_in(char **args);
int		ft_include_built_in(char **args);
void	ft_built_in_exe(char **args, int flag, t_parameters *p);
//UNSET.C
void	ft_unset(char **matrix, char ***env_copy, t_parameters **p);
//EXEC_MANAGER.C
void	exec_block_1(t_arg *args, t_parameters *p, int index);
void	exec_block_2(t_arg *args, t_parameters *p, int index);
void	exec_block_3(t_arg *args, t_parameters *p, int index);
void	block_exe(t_arg *args, t_parameters *p, int toggle);
void	ft_command_error(char *matrix1, t_parameters *p);
void	exec_sig_redir(t_parameters *p, int index, int toggle);
//REDIRECT_OUT.C
int		ft_count_writes(char const *s);
char	**ft_set_writes(char *argu);
char	*ft_cut_writes(char *argu);
void	set_redir_out(t_parameters *p, int toggle, int index);
void	find_redir_out(t_parameters *p, int i, int j, int toggle);
//REDIRECT_OUT2.C
void	set_par(int *par);
void	cut_writes_exe(int *par, char *argu);
void	set_writes_exe(int *par, char *argu);
void	set_writes_exe2(int *par, char *argu, char **matrix);
void	find_redir_out_exe(t_parameters *p, int toggle, char *temp, int *par);
// REDIRECT_IN.C
int		ft_count_reads(char const *s);
char	**ft_set_reads(char *argu);
char	*ft_cut_reads(char *argu);
void	set_redir_in(t_parameters *p, int index);
void	find_redir_in(t_parameters *p, int i, int j, int toggle);
//REDIRECT_IN2.C
void	update_param(int *param, char const *s);
void	set_reads_exe2(int *par, char *argu, char **matrix);
void	set_reads_exe(int *par, char *argu);
void	cut_reads_exe(int *par, char *argu);
char	*find_redir_in_exe(t_parameters *p, int i, int j, int *par);
//REDIRECT_FIX.C
void	cut_writes_exe_fix(int *par, char *argu);
void	cut_reads_exe_fix(int *par, char *argu);
void	redir_in_set_param(int	*par);
void	find_redir_in_2(t_parameters *p, int *par, int toggle, char *temp);
void	ft_opening(t_parameters *p, int *par, char *tmp);
//GET_NEXT_LINE.C
char	*find_line(char *str);
char	*solve_problems(char *buffer);
char	*get_next_line(int fd);
//GET_NEXT_LINE_UTILS.C
char	*ft_strjoin_g(char *s1, char *s2);
int		ft_strlen_g(char *s);
int		check_newline(char *str);
int		ft_here_doc(char *lim, t_parameters *p);
int		ft_find_quote(char *str);
//GET_NEXT_LINE_UTILS2.C
void	ft_here_doc_exe(t_parameters *p, char *lim, int fd, int std);
void	ft_here_doc_exe2(t_parameters *p, char *lim, char *temp, int fd);
void	ft_doc_sig(t_parameters *p, int std);
void	ft_here_doc_exe3(char *lim, char *temp1);
void	ft_here_doc_exe4(char *temp);
//SIGNAL.C
void	handle_sigint(int sig);
void	child_sigint(int sig);
void	child_sigquit(int sig);
void	heredoc_sigint(int sig);
void	heredoc_sigquit(int sig);
//PROMPT_ERR.C
int		prompt_err_manager(char *prompt);
int		check_redir(char *prompt, char c);
void	ft_put_fd_err(char *str, int toggle);
void	check_redir_exe(char *prompt, int *flags, int i, char c);
//PIPES.c
int		count_pipes(char *prompt);
int		check_pipes(char *prompt);
//PWD.C
void	ft_pwd(t_parameters *p);
//MAIN_EXE.C
void	main_exe_1(t_parameters *p);
void	main_exe_2(t_parameters *p);
void	main_exe_3(t_parameters *p);
void	main_exe_4(t_parameters *p);
#endif

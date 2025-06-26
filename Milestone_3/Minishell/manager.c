/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 14:22:31 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/17 15:08:54 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	parse_manager(t_parameters *p)
{
	char	**args;

	p->p_len = count_pipes(p->str) + 2;
	p->p_args = ft_calloc(p->p_len, sizeof(t_arg));
	p->n_pipes = count_pipes(p->str);
	p->n_total_pipes = p->n_pipes;
	args = ft_split_args(p->str, '|');
	parse_manager_exe(p, args);
}

//param[0] -> i		param[1] -> j
//param[2] -> len	param[3] -> count
void	ft_handle_empties(char ***matrix)
{
	int		param[4];
	char	**temp;

	param[3] = 0;
	param[0] = -1;
	param[2] = ft_strlen_matrix(*matrix);
	temp = ft_copy_matrix(*matrix);
	while (++param[0] < param[2])
	{
		if ((*matrix)[param[0]] == NULL || (*matrix)[param[0]][0] == '\0')
			param[3]++;
	}
	ft_free_matrix(*matrix, 0);
	*matrix = ft_calloc(ft_strlen_matrix(temp) - param[3] + 1, sizeof(char *));
	param[0] = -1;
	param[1] = 0;
	while (++param[0] < param[2])
	{
		if (temp[param[0]] != NULL && temp[param[0]][0] != '\0')
		{
			(*matrix)[param[1]] = ft_strdup(temp[param[0]]);
			param[1]++;
		}
	}
	ft_free_matrix(temp, 0);
}

void	parse_manager_exe(t_parameters *p, char **args)
{
	int	status;
	int	len;
	int	i[2];

	len = ft_strlen_matrix(args);
	ft_args_cleaning(p, len, args);
	i[0] = -1;
	while (++i[0] < len)
	{
		i[1] = -1;
		while (++i[1] < ft_strlen_matrix(p->p_args[i[0]].arg))
			p->p_args[i[0]].arg[i[1]] = prompt_clear(p->p_args[i[0]].arg[i[1]]);
	}
	ft_parse_manager_exe_2(p, args, len, i);
	if (waitpid(p->pid_child, &status, 0) != -1)
	{
		if (WIFEXITED(status))
			p->dollar = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			p->dollar = WTERMSIG(status) + 128;
	}
	while (wait(&len) != -1)
		;
	ft_free_arg(p, p->p_args);
}

void	ft_command_error(char *matrix1, t_parameters *p)
{
	char	*str_err;
	int		fd;

	fd = access(matrix1, F_OK);
	if (fd == -1)
	{
		str_err = ft_strjoin(matrix1, ": command not found\n");
		ft_putstr_fd(str_err, 2);
		free(str_err);
		p->dollar = 127;
	}
	else
	{
		str_err = ft_strjoin(matrix1, ": Is a directory\n");
		ft_putstr_fd(str_err, 2);
		free(str_err);
		p->dollar = 126;
	}
}

void	exec_manager(t_arg *args, t_parameters *p, int index)
{
	if (p->n_total_pipes == 0)
		exec_block_1(args, p, index);
	else
	{
		if (p->n_pipes != 0)
			exec_block_2(args, p, index);
		else
			exec_block_3(args, p, index);
		dup2(p->fd[0], 0);
		close(p->fd[0]);
		close(p->fd[1]);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_manager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:23:28 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/23 14:23:40 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exec_block_1(t_arg *args, t_parameters *p, int index)
{
	int	id;

	exec_sig_redir(p, index, 2);
	if (p->flag_heredoc == 1)
		return ;
	p->lastchild = 1;
	if (args->flag_in == 1 && args->flag_out == 1)
	{
		if (ft_is_built_in(args->arg) != 0)
			ft_built_in_exe(args->arg, ft_is_built_in(args->arg), p);
		else
		{
			id = fork();
			if (id == 0)
			{
				block_exe(args, p, 0);
				ft_execute(p, args->arg, p->env_copy);
				ft_command_error(args->arg[0], p);
				ft_exec_cleaning(p);
			}
			else
				p->pid_child = id;
		}
	}
}

void	exec_block_2(t_arg *args, t_parameters *p, int index)
{
	int	id;

	p->n_pipes--;
	exec_sig_redir(p, index, 1);
	if (p->flag_heredoc == 1)
		return ;
	p->lastchild = 0;
	if (args->flag_in == 1 && args->flag_out == 1)
	{
		id = fork();
		if (id == 0)
			block_exe(args, p, 1);
		else
			p->pid_child = id;
	}
}

void	exec_block_3(t_arg *args, t_parameters *p, int index)
{
	int	id;

	p->n_pipes--;
	exec_sig_redir(p, index, 2);
	if (p->flag_heredoc == 1)
		return ;
	p->lastchild = 1;
	if (args->flag_in == 1 && args->flag_out == 1)
	{
		id = fork();
		if (id == 0)
			block_exe(args, p, 1);
		else
			p->pid_child = id;
	}
}

void	exec_sig_redir(t_parameters *p, int index, int toggle)
{
	signal(SIGINT, child_sigint);
	signal(SIGQUIT, child_sigquit);
	set_redir_in(p, index);
	set_redir_out(p, toggle, index);
}

void	block_exe(t_arg *args, t_parameters *p, int toggle)
{
	close(p->fd[0]);
	close(p->fd[1]);
	close(p->write_1);
	close(p->read_0);
	if (toggle == 1)
	{
		if (ft_is_built_in(args->arg) != 0)
		{
			ft_built_in_exe(args->arg, ft_is_built_in(args->arg), p);
			ft_exec_cleaning(p);
		}
		else
		{
			ft_execute(p, args->arg, p->env_copy);
			ft_command_error(args->arg[0], p);
			ft_exec_cleaning(p);
		}
	}
}

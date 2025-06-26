/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_exe.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 15:22:56 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/17 15:41:50 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	main_exe_1(t_parameters *p)
{
	if (p->flag_heredoc == 1)
		p->flag_heredoc = 0;
	if (p->prompt != NULL)
		free (p->prompt);
	p->prompt = ft_prompt(p->env_copy, p);
	if (p->tmp != NULL)
		free (p->tmp);
	dup2(p->write_1, 1);
	dup2(p->read_0, 0);
	signal(SIGINT, handle_sigint);
	signal(SIGQUIT, SIG_IGN);
	unlink(".heredoc");
	p->tmp = readline(p->prompt);
	if ((g_var_signal == 130 && p->lastchild == 0) || g_var_signal == 132)
		p->dollar = 130;
	else if (g_var_signal == 131)
		p->dollar = 131;
	g_var_signal = 0;
}

void	main_exe_2(t_parameters *p)
{
	close(p->read_0);
	close(p->write_1);
	free(p->str);
	free(p->tmp);
	ft_free_matrix(p->env_copy, 0);
	free(p->user);
	free(p->place);
	free(p->prompt);
}

void	main_exe_3(t_parameters *p)
{
	if (p->str != NULL)
		free (p->str);
	p->str = ft_strdup(p->tmp);
	add_history(p->str);
}

void	main_exe_4(t_parameters *p)
{
	parse_manager(p);
	ft_free_3d_matrix(p->p_writes, 0);
	ft_free_3d_matrix(p->p_reads, 0);
}

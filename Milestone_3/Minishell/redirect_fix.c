/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_fix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/11 14:55:10 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/17 17:50:25 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cut_reads_exe_fix(int *par, char *argu)
{
	if ((argu[par[0]] == ' ' || argu[par[0]] == '<') && \
	par[1] == 0 && par[3] == 1)
	{
		par[3] = 0;
		par[2] = 0;
		if (argu[par[0]] == '<')
		{
			par[0]--;
			par[6] = 1;
		}
	}
}

void	cut_writes_exe_fix(int *par, char *argu)
{
	if ((argu[par[0]] == ' ' || argu[par[0]] == '>') && \
	par[1] == 0 && par[3] == 1)
	{
		par[3] = 0;
		par[2] = 0;
		if (argu[par[0]] == '>')
		{
			par[0]--;
			par[6] = 1;
		}
	}
}

void	redir_in_set_param(int	*par)
{
	par[0] = -1;
	par[1] = 0;
	par[2] = 0;
	par[3] = 0;
}

void	find_redir_in_2(t_parameters *p, int *par, int toggle, char *temp)
{
	if (par[3] != -1)
	{
		if (toggle == 1)
			dup2(par[3], 0);
		close (par[3]);
	}
	else
	{
		ft_put_fd_err(temp, 0);
		if (toggle == 1)
			p->p_args[0].flag_in = 0;
	}
}

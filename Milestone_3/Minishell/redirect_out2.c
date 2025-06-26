/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_out2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 15:33:06 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/11 15:18:36 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	set_par(int *par)
{
	par[0] = -1;
	par[2] = 0;
	par[3] = 0;
	par[5] = 0;
	par[6] = 1;
	par[4] = 0;
}

void	cut_writes_exe(int *par, char *argu)
{
	if (argu[par[0]] == '\'' && par[1] == 0)
		par[1] = 1;
	else if (argu[par[0]] == '\'' && par[1] == 1)
		par[1] = 0;
	else if (argu[par[0]] == '\"' && par[1] == 0)
		par[1] = 2;
	else if (argu[par[0]] == '\"' && par[1] == 2)
		par[1] = 0;
	else if (argu[par[0]] == '>' && par[1] == 0 && par[2] == 0)
		par[2] = 1;
	else if (argu[par[0]] == '>' && par[1] == 0 && par[2] == 1 && par[3] == 0)
		par[2] = 2;
	else if ((argu[par[0]] != ' ' && argu[par[0]] != '>') && \
	par[1] == 0 && (par[2] == 2 || par[2] == 1))
		par[3] = 1;
	cut_writes_exe_fix(par, argu);
}

void	set_writes_exe(int *par, char *argu)
{
	if (argu[par[0]] == '\'' && par[2] == 0)
		par[2] = 1;
	else if (argu[par[0]] == '\'' && par[2] == 1)
		par[2] = 0;
	else if (argu[par[0]] == '\"' && par[2] == 0)
		par[2] = 2;
	else if (argu[par[0]] == '\"' && par[2] == 2)
		par[2] = 0;
	if (argu[par[0]] == '>' && par[2] == 0 && par[3] == 0)
	{
		par[1] = par[0];
		par[3] = 1;
	}
	else if (argu[par[0]] == '>' && par[2] == 0 && \
		par[3] == 1 && par[4] == 0)
		par[3] = 2;
	else if ((argu[par[0]] != ' ' && argu[par[0]] != '>') && \
	par[2] == 0 && (par[3] == 2 || par[3] == 1))
	{
		par[4] = 1;
		par[6] = 0;
	}
}

void	set_writes_exe2(int *par, char *argu, char **matrix)
{
	if ((argu[par[0]] == ' ' || argu[par[0]] == '>') && \
	par[2] == 0 && par[4] == 1)
	{
		matrix[par[5]++] = ft_substr(argu, par[1], ft_strlen(argu) - \
		par[1] - (ft_strlen(argu) - par[0]));
		par[4] = 0;
		par[3] = 0;
		if (argu[par[0]] == '>')
			par[0]--;
	}
}

void	find_redir_out_exe(t_parameters *p, int toggle, char *temp, int *par)
{
	if (par[3] != -1)
	{
		if (toggle == 1)
			dup2(par[3], 1);
		close(par[3]);
	}
	else
	{
		ft_put_fd_err(temp, 1);
		if (toggle == 1)
			p->p_args[0].flag_out = 0;
	}
}

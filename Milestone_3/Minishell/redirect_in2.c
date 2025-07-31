/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_in2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/09 14:29:59 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/17 14:49:51 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	update_param(int *param, char const *s)
{
	if (s[param[0]] == '\"' && param[1] == 0 && param[2] == 0)
		param[2] = 1;
	else if (s[param[0]] == '\'' && param[1] == 0 && param[2] == 0)
		param[1] = 1;
	else if (s[param[0]] == '\"' && param[2] == 1 && param[1] == 0)
		param[2] = 0;
	else if (s[param[0]] == '\'' && param[1] == 1 && param[2] == 0)
		param[1] = 0;
}

void	set_reads_exe2(int *par, char *argu, char **matrix)
{
	if ((argu[par[0]] == ' ' || argu[par[0]] == '<') && \
	par[2] == 0 && par[4] == 1)
	{
		matrix[par[5]++] = ft_substr(argu, par[1], ft_strlen(argu) - \
		par[1] - (ft_strlen(argu) - par[0]));
		par[4] = 0;
		par[3] = 0;
		if (argu[par[0]] == '<')
			par[0]--;
	}
}

void	set_reads_exe(int *par, char *argu)
{
	if (argu[par[0]] == '\'' && par[2] == 0)
		par[2] = 1;
	else if (argu[par[0]] == '\'' && par[2] == 1)
		par[2] = 0;
	else if (argu[par[0]] == '\"' && par[2] == 0)
		par[2] = 2;
	else if (argu[par[0]] == '\"' && par[2] == 2)
		par[2] = 0;
	else if (argu[par[0]] == '<' && par[2] == 0 && par[3] == 0)
	{
		par[1] = par[0];
		par[3] = 1;
	}
	else if (argu[par[0]] == '<' && par[2] == 0 && par[3] == 1 && par[4] == 0)
		par[3] = 2;
	else if ((argu[par[0]] != ' ' && argu[par[0]] != '<') && \
	(par[3] == 2 || par[3] == 1))
	{
		par[4] = 1;
		par[6] = 0;
	}
}

void	cut_reads_exe(int *par, char *argu)
{
	if (argu[par[0]] == '\'' && par[1] == 0)
		par[1] = 1;
	else if (argu[par[0]] == '\'' && par[1] == 1)
		par[1] = 0;
	else if (argu[par[0]] == '\"' && par[1] == 0)
		par[1] = 2;
	else if (argu[par[0]] == '\"' && par[1] == 2)
		par[1] = 0;
	else if (argu[par[0]] == '<' && par[1] == 0 && par[2] == 0)
		par[2] = 1;
	else if (argu[par[0]] == '<' && par[1] == 0 && par[2] == 1 && par[3] == 0)
		par[2] = 2;
	else if ((argu[par[0]] != ' ' && argu[par[0]] != '<') && \
	(par[2] == 2 || par[2] == 1))
		par[3] = 1;
	cut_reads_exe_fix(par, argu);
}

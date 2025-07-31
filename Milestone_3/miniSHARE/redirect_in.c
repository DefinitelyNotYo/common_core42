/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_in.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:01:41 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/17 17:56:24 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//param[0] -> i			param[1] -> flag_q
//param[2] -> flag_Q	param[3] -> toggle
//param[4] -> count;
int	ft_count_reads(char const *s)
{
	int	param[5];

	set_arguments(param);
	while (s[++param[0]] != '\0')
	{
		update_param(param, s);
		if (param[1] == 0 && param[2] == 0)
		{
			if (s[param[0]] == '<' && param[3] == 0)
				param[3] = 1;
			else if (s[param[0]] == '<' && param[3] == 1)
				param[3] = 2;
			if (s[param[0]] != ' ' && (param[3] == 1 || param[3] == 2))
			{
				param[3] = 0;
				param[4]++;
			}
		}
	}
	if (param[4] > 1)
		return (param[4]);
	else
		return (1);
}

char	*ft_cut_reads(char *argu)
{
	char	*temp;
	int		par[7];

	par[0] = -1;
	par[1] = 0;
	par[2] = 0;
	par[3] = 0;
	par[4] = 0;
	temp = ft_calloc(ft_strlen(argu) + 1, 1);
	if (!temp)
		return (NULL);
	while (argu[++par[0]] != '\0')
	{
		par[6] = 0;
		par[5] = par[0];
		cut_reads_exe(par, argu);
		if (par[2] == 0 && par[3] == 0 && par[6] == 0)
			temp[par[4]++] = argu[par[5]];
	}
	return (free(argu), temp);
}

char	**ft_set_reads(char *argu)
{
	char	**matrix;
	int		par[7];

	set_par(par);
	matrix = (char **)ft_calloc((ft_count_reads(argu) + 1), sizeof(char *));
	if (!matrix)
		return (NULL);
	while (argu[++par[0]] != '\0')
	{
		set_reads_exe(par, argu);
		set_reads_exe2(par, argu, matrix);
	}
	if (par[2] == 0 && par[4] == 1)
		matrix[par[5]++] = ft_substr(argu, par[1], ft_strlen(argu) - \
		par[1] - (ft_strlen(argu) - par[0]));
	if (par[6] == 1)
		matrix[par[5]++] = ft_strdup("std");
	return (matrix);
}

void	set_redir_in(t_parameters *p, int index)
{
	int	j;

	j = -1;
	while (++j < ft_strlen_matrix(p->p_reads[index]))
	{
		if (p->flag_heredoc == 1)
			break ;
		if (!(ft_strncmp(p->p_reads[index][j], "std", 3) == 0))
		{
			if (j == ft_strlen_matrix(p->p_reads[index]) - 1)
				find_redir_in(p, index, j, 1);
			else
				find_redir_in(p, index, j, 0);
		}
	}
}

void	find_redir_in(t_parameters *p, int i, int j, int toggle)
{
	char	*temp;
	int		par[4];

	redir_in_set_param(par);
	temp = ft_calloc(ft_strlen(p->p_reads[i][j]), 1);
	while (p->p_reads[i][j][++par[0]] != '\0')
	{
		if (p->p_reads[i][j][par[0]] == '<')
			par[2]++;
		if (p->p_reads[i][j][par[0]] != ' ' && p->p_reads[i][j][par[0]] != '<')
			temp[par[1]++] = p->p_reads[i][j][par[0]];
	}
	if (par[2] == 1)
	{
		temp = prompt_clear(temp);
		par[3] = open(temp, O_RDWR | O_APPEND, 0777);
	}
	if (par[2] == 2)
		par[3] = ft_here_doc(temp, p);
	find_redir_in_2(p, par, toggle, temp);
	free(temp);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect_out.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 15:10:15 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/11 15:01:03 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//param[0] -> i			param[1] -> flag_q
//param[2] -> flag_Q	param[3] -> toggle
//param[4] -> count;
int	ft_count_writes(char const *s)
{
	int	param[5];

	set_arguments(param);
	while (s[++param[0]] != '\0')
	{
		update_param(param, s);
		if (param[1] == 0 && param[2] == 0)
		{
			if (s[param[0]] == '>' && param[3] == 0)
				param[3] = 1;
			else if (s[param[0]] == '>' && param[3] == 1)
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

char	*ft_cut_writes(char *argu)
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
		cut_writes_exe(par, argu);
		if (par[2] == 0 && par[3] == 0 && par[6] == 0)
			temp[par[4]++] = argu[par[5]];
	}
	return (free(argu), temp);
}

char	**ft_set_writes(char *argu)
{
	char	**matrix;
	int		par[7];

	set_par(par);
	matrix = (char **)ft_calloc((ft_count_writes(argu) + 1), sizeof(char *));
	if (!matrix)
		return (NULL);
	while (argu[++par[0]] != '\0')
	{
		set_writes_exe(par, argu);
		set_writes_exe2(par, argu, matrix);
	}
	if (par[2] == 0 && par[4] == 1)
		matrix[par[5]++] = ft_substr(argu, par[1], ft_strlen(argu) - \
		par[1] - (ft_strlen(argu) - par[0]));
	if (par[6] == 1)
		matrix[par[5]++] = ft_strdup("std");
	return (matrix);
}

//toggle = 1 [scrivi su pipe], toggle = 2 [scrivi su terminale]
void	set_redir_out(t_parameters *p, int toggle, int index)
{
	int	j;

	j = -1;
	while (++j < ft_strlen_matrix(p->p_writes[index]))
	{
		if ((ft_strncmp(p->p_writes[index][j], "std", 3) == 0) && toggle == 1)
			dup2(p->fd[1], 1);
		else if ((ft_strncmp(p->p_writes[index][j], "std", 3) == 0) && \
			toggle == 2)
			dup2(p->write_1, 1);
		else
		{
			if (j == ft_strlen_matrix(p->p_writes[index]) - 1)
				find_redir_out(p, index, j, 1);
			else
				find_redir_out(p, index, j, 0);
		}
	}
}

void	find_redir_out(t_parameters *p, int i, int j, int toggle)
{
	char	*temp;
	int		par[4];

	par[0] = -1;
	par[1] = 0;
	par[2] = 0;
	temp = ft_calloc(ft_strlen(p->p_writes[i][j]), 1);
	while (p->p_writes[i][j][++par[0]] != '\0')
	{
		if (p->p_writes[i][j][par[0]] == '>')
			par[2]++;
		if (p->p_writes[i][j][par[0]] != ' ' && \
			p->p_writes[i][j][par[0]] != '>')
			temp[par[1]++] = p->p_writes[i][j][par[0]];
	}
	temp = prompt_clear(temp);
	if (par[2] == 1)
		par[3] = open(temp, O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (par[2] == 2)
		par[3] = open(temp, O_RDWR | O_APPEND | O_CREAT, 0777);
	find_redir_out_exe(p, toggle, temp, par);
	free (temp);
}

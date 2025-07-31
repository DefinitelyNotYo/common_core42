/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_doc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:05:54 by cciapett          #+#    #+#             */
/*   Updated: 2025/06/13 17:08:08 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_evaluate_toggle(char **matrix, t_dollar_par	*par)
{
	if (matrix[par->i][par->j] == '\'' && (par)->toggle == 0)
		(par)->toggle = 1;
	else if (matrix[par->i][par->j] == '\'' && (par)->toggle == 1)
		(par)->toggle = 0;
	else if (matrix[par->i][par->j] == '\"' && (par)->toggle == 0)
		(par)->toggle = 2;
	else if (matrix[par->i][par->j] == '\"' && (par)->toggle == 2)
		(par)->toggle = 0;
}

void	ft_dollar_exe(t_dollar_par *par, char **matrix, int flag)
{
	par->temp = ft_strdup(matrix[par->i]);
	if (matrix[par->i] != NULL)
		free(matrix[par->i]);
	par->start = ft_substr(par->temp, 0, par->j);
	if (flag == 0)
		par->end = ft_strdup(par->temp + par->j + 1);
	else
		par->end = ft_strdup(par->temp + par->j);
	matrix[par->i] = ft_strjoin(par->start, par->end);
	if (par->temp != NULL)
		free(par->temp);
	if (par->start != NULL)
		free(par->start);
	if (par->end != NULL)
		free(par->end);
}

void	ft_call_funct_hd(t_dollar_par *par, char **matrix)
{
	if (par->toggle == 0)
		ft_dollar_exe(par, matrix, 0);
	else if (par->toggle == 1 || par->toggle == 2)
		ft_dollar_exe(par, matrix, 1);
}

void	ft_dollar_process_hd(char **matrix, t_dollar_par *par, t_parameters *p)
{
	while (matrix[par->i][++par->j] != '\0')
	{
		ft_evaluate_toggle(matrix, par);
		if (matrix[par->i][par->j] == '$' && matrix[par->i][par->j + 1] != '\0' \
			&& matrix[par->i][par->j + 1] != '\'' \
			&& matrix[par->i][par->j + 1] != '\"' )
		{
			if (ft_isalnum_env(matrix[par->i][par->j + 1]) == 0 && \
			matrix[par->i][par->j + 1] != '?')
			{
				ft_call_funct_hd(par, matrix);
				continue ;
			}
			free_param(&par);
			ft_prv_aft(&par, matrix);
			ft_inner_process(p, par, matrix);
			if (par->k == ft_strlen_matrix(p->env_copy))
				ft_not_find_env(&par, matrix, p);
		}
	}
}

void	ft_handle_dollar_doc(char **matrix, t_parameters *p)
{
	t_dollar_par	*par;

	ft_initialize_dollar(&par);
	while (matrix && matrix[++par->i] != NULL)
	{
		par->j = -1;
		ft_dollar_process_hd(matrix, par, p);
	}
	free_param(&par);
	free(par);
}

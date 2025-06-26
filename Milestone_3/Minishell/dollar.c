/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 11:12:46 by cciapett          #+#    #+#             */
/*   Updated: 2025/06/13 17:12:34 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isalnum_env(int c)
{
	if (ft_isdigit(c) == 2048 || ft_isalpha(c) == 1024 || c == 95)
		return (8);
	else
		return (0);
}

void	ft_call_funct(t_dollar_par *par, char **matrix)
{
	if (par->toggle == 0)
		ft_dollar_exe(par, matrix, 0);
	else if (par->toggle == 2)
		ft_dollar_exe(par, matrix, 1);
}

void	ft_inner_process(t_parameters *p, t_dollar_par *par, char **matrix)
{
	while (p->env_copy[++par->k] != NULL)
	{
		if (ft_strncmp(par->s, p->env_copy[par->k], ft_strlen(par->s)) == 0 \
		&& p->env_copy[par->k][ft_strlen(par->s)] == '=')
		{
			ft_find_env(&par, matrix, p);
			break ;
		}
	}
}

void	ft_dollar_process(char **matrix, t_dollar_par *par, t_parameters *p)
{
	while (matrix[par->i][++par->j] != '\0')
	{
		ft_evaluate_toggle(matrix, par);
		if (matrix[par->i][par->j] == '$' && matrix[par->i][par->j + 1] != '\0')
		{
			if (par->toggle != 1)
			{
				if (ft_isalnum_env(matrix[par->i][par->j + 1]) == 0 \
				&& matrix[par->i][par->j + 1] != '?')
				{
					ft_call_funct(par, matrix);
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
}

void	ft_handle_dollar(char **matrix, t_parameters *p)
{
	t_dollar_par	*par;

	ft_initialize_dollar(&par);
	while (matrix && matrix[++par->i] != NULL)
	{
		par->j = -1;
		ft_dollar_process(matrix, par, p);
	}
	free_param(&par);
	free(par);
}

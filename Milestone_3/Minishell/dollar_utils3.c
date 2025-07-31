/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:12:42 by cciapett          #+#    #+#             */
/*   Updated: 2025/06/13 17:12:03 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_initialize_dollar(t_dollar_par **par)
{
	*par = ft_calloc(sizeof(t_dollar_par), 1);
	(*par)->i = -1;
	(*par)->s = NULL;
	(*par)->prv_str = NULL;
	(*par)->aft_str = NULL;
	(*par)->toggle = 0;
	(*par)->temp = NULL;
	(*par)->start = NULL;
	(*par)->end = NULL;
}

void	ft_find_env(t_dollar_par **par, char **matrix, t_parameters *p)
{
	int	len_s;
	int	len_prvstr;

	len_s = ft_strlen((*par)->s);
	len_prvstr = ft_strlen((*par)->prv_str);
	(*par)->temp = ft_superjoin((*par)->prv_str, (p->env_copy)[(*par)->k] + \
	len_s + 1);
	free(matrix[(*par)->i]);
	matrix[(*par)->i] = ft_superjoin((*par)->temp, (*par)->aft_str);
	free((*par)->temp);
	(*par)->j = len_prvstr + \
	ft_strlen((p->env_copy)[(*par)->k] + len_s + 1) - 1;
}

void	ft_not_find_env(t_dollar_par **par, char **matrix, t_parameters *p)
{
	if (ft_strlen((*par)->s) == 0 && (*par)->aft_str[0] != '?')
	{
		(*par)->temp = ft_superjoin((*par)->prv_str, "$");
		(*par)->j = ft_strlen((*par)->temp) - 1;
		free(matrix[(*par)->i]);
		matrix[(*par)->i] = ft_superjoin((*par)->temp, (*par)->aft_str);
		if ((*par)->temp)
			free((*par)->temp);
	}
	else if (ft_strlen((*par)->s) == 0 && (*par)->aft_str[0] == '?')
		ft_search_questionmark(&matrix[(*par)->i], p);
	else
	{
		free(matrix[(*par)->i]);
		matrix[(*par)->i] = ft_superjoin((*par)->prv_str, (*par)->aft_str);
		(*par)->j = ft_strlen((*par)->prv_str) - 1;
	}
}

void	ft_prv_aft(t_dollar_par **par, char **matrix)
{
	int	len_s;
	int	len_prvstr;

	if ((*par)->j != 0)
		(*par)->prv_str = ft_memcopy(matrix[(*par)->i], (*par)->j);
	else
		(*par)->prv_str = NULL;
	(*par)->k = -1;
	(*par)->s = ft_dollar(matrix[(*par)->i] + (*par)->j + 1);
	len_s = ft_strlen((*par)->s);
	len_prvstr = ft_strlen((*par)->prv_str);
	if (matrix[(*par)->i] + len_prvstr + len_s + 1 != (void *) '\0')
		(*par)->aft_str = ft_after_dollar(matrix[(*par)->i] + len_prvstr \
		+ len_s + 1);
}

void	free_param(t_dollar_par **par)
{
	if ((*par)->s != NULL)
		free((*par)->s);
	if ((*par)->prv_str != NULL)
		free((*par)->prv_str);
	if ((*par)->aft_str != NULL)
		free((*par)->aft_str);
}

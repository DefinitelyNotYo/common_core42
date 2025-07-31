/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:43:08 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/05 14:03:29 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_matrix(char **matrix, int i)
{
	if (!matrix)
		return ;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free (matrix);
}

void	ft_free_exec(t_pathfinder *p)
{
	ft_free_matrix(p->split_paths, 0);
	if (p->path != NULL)
		free (p->path);
	if (p != NULL)
		free(p);
}

void	ft_free_3d_matrix(char ***matrix, int i)
{
	if (!matrix)
		return ;
	while (matrix[i] != NULL)
	{
		ft_free_matrix(matrix[i], 0);
		i++;
	}
	free (matrix);
}

void	ft_exec_cleaning(t_parameters *p)
{
	ft_free_matrix(p->env_copy, 0);
	ft_free_3d_matrix(p->p_writes, 0);
	ft_free_3d_matrix(p->p_reads, 0);
	free (p->prompt);
	free(p->str);
	free(p->user);
	free(p->place);
	ft_free_arg(p, p->p_args);
	exit(p->dollar);
}

void	ft_free_arg(t_parameters *p, t_arg *arg)
{
	int	i;

	i = -1;
	while (++i < p->p_len - 1)
		ft_free_matrix(arg[i].arg, 0);
	free(arg);
}

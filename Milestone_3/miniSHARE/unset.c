/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 18:11:21 by cciapett          #+#    #+#             */
/*   Updated: 2025/06/14 12:15:06 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_args_to_unset(char ***env_copy, char **matrix, t_parameters **p)
{
	int	i;
	int	j;
	int	cont;

	i = -1;
	cont = 0;
	while (matrix[++i] != NULL)
	{
		j = 0;
		if (ft_isalpha_env(matrix[i][0]) != 1024 \
		|| ft_avoid_plus(matrix[i]) == 1 || ft_faya(matrix[i], "/") == 1)
		{
			(*p)->dollar = 1;
			continue ;
		}
		while ((*env_copy)[j] != NULL)
		{
			if (ft_strncmp((*env_copy)[j], matrix[i], ft_strlen(matrix[i])) \
			== 0 && ft_strlen(matrix[i]) == ft_strlen((*env_copy)[j]))
				cont++;
			j++;
		}
	}
	return (cont);
}

int	ft_check_unset(char *env_copy_temp, char **matrix)
{
	int	i;
	int	size;

	i = -1;
	size = ft_strlen(env_copy_temp);
	while (env_copy_temp[++i] != '\0')
	{
		if (env_copy_temp[i] == '=')
		{
			size = i;
			break ;
		}
	}
	i = -1;
	while (matrix[++i] != NULL)
		if (ft_strncmp(env_copy_temp, matrix[i], size) == 0)
			return (1);
	return (0);
}

// 127 if command not found or 126 if is a directpry

void	ft_unset(char **matrix, char ***env_copy, t_parameters **p)
{
	int		i;
	int		j;
	int		cont;
	char	**env_copy_temp;
	int		size;

	(*p)->dollar = 0;
	cont = ft_args_to_unset(env_copy, matrix, p);
	env_copy_temp = ft_copy_matrix(*env_copy);
	ft_free_matrix(*env_copy, 0);
	size = ft_strlen_matrix(env_copy_temp) - cont + 1;
	*env_copy = (char **)ft_calloc(size, sizeof(char *));
	i = -1;
	j = 0;
	while (env_copy_temp[++i] != NULL)
	{
		if (ft_check_unset(env_copy_temp[i], matrix) == 0)
		{
			(*env_copy)[j] = ft_strdup(env_copy_temp[i]);
			j++;
		}
	}
	ft_free_matrix(env_copy_temp, 0);
	(*env_copy)[j] = NULL;
}

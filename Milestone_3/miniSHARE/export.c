/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 16:26:40 by cciapett          #+#    #+#             */
/*   Updated: 2025/06/16 16:10:20 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_free_export(char	**name, char **value)
{
	if (*name != NULL)
		free(*name);
	if (*value != NULL)
		free(*value);
}

void	ft_add_value(char ***env_copy, char *str, int pos, int *index)
{
	char	*name;
	char	*value;
	int		i;

	i = -1;
	name = ft_memcopy(str, pos);
	value = ft_memcopy(str + pos + 2, ft_strlen(str) - pos);
	while ((*env_copy)[++i] != NULL)
	{
		if (ft_strncmp((*env_copy)[i], name, ft_strlen(name)) == 0 \
		&& (*env_copy)[i][ft_strlen(name)] == '=')
		{
			ft_copy_str2(value, &(*env_copy)[i]);
			break ;
		}
		else if (ft_strncmp((*env_copy)[i], name, ft_strlen(name)) == 0 \
		&& (*env_copy)[i][ft_strlen(name)] == '\0')
		{
			ft_copy_str(name, value, &(*env_copy)[i]);
			break ;
		}
	}
	if ((*env_copy)[i] == NULL)
		ft_create_value_plus(env_copy, str, pos + 1, index);
	ft_free_export(&name, &value);
}

void	ft_init(int *index, int *len, unsigned char *dollar)
{
	index[0] = -1;
	index[1] = 0;
	index[2] = 0;
	index[3] = -1;
	len = 0;
	*dollar = 0;
}

void	ft_export_new_env(int *index, char ***env_copy, char *matrix_str)
{
	ft_search_plus(matrix_str, env_copy, index);
	index[2]++;
}

int	ft_export(char **matrix, char ***env_copy, t_parameters *p)
{
	int		index[4];
	int		len;
	char	**env_copy_temp;

	ft_init(index, &len, &p->dollar);
	if (ft_strlen_matrix(matrix) == 1)
	{
		ft_bubble_sort(env_copy);
		while ((*env_copy)[++index[0]] != NULL)
			ft_export_add_quotes((*env_copy)[index[0]]);
	}
	else if (ft_strlen_matrix(matrix) > 1)
	{
		index[0] = -1;
		ft_init_export_mtx(env_copy, &env_copy_temp, &matrix, &len);
		while (env_copy_temp[++index[0]] != NULL)
			ft_search_plus(env_copy_temp[index[0]], env_copy, index);
		while (matrix[++index[1]] != NULL)
			if (ft_check_export(matrix[index[1]], p) == 0)
				ft_export_new_env(index, env_copy, matrix[index[1]]);
		(*env_copy)[index[0] + index[1] - 1] = NULL;
		ft_free_matrix(env_copy_temp, 0);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:55:37 by cciapett          #+#    #+#             */
/*   Updated: 2025/06/14 10:53:07 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_previous_dir(char *curr_dir)
{
	int		i;
	char	*dir;

	dir = NULL;
	i = ft_strlen(curr_dir);
	while (i > 0)
	{
		if (curr_dir[i] == '/')
		{
			dir = ft_memcopy(curr_dir, i);
			break ;
		}
		i--;
	}
	if (dir == NULL)
		chdir("/");
	else
	{
		chdir(dir);
		free(dir);
	}
}

char	*ft_get_env(char *str, char **env_copy)
{
	int	i;

	i = 0;
	while (env_copy[i] != NULL)
	{
		if (ft_strncmp(str, env_copy[i], ft_strlen(str)) == 0 \
		&& env_copy[i][ft_strlen(str)] == '=')
			return (env_copy[i] + ft_strlen(str) + 1);
		i++;
	}
	return (NULL);
}

int	ft_search_oldpwd(char **env_copy)
{
	int	i;
	int	flag;

	i = -1;
	flag = 0;
	while (env_copy[++i] != NULL)
	{
		if (ft_strncmp("OLDPWD", env_copy[i], 6) == 0)
			flag = 1;
	}
	return (flag);
}

void	ft_create_oldpwd(char ***env_copy)
{
	int		i;
	char	**env_temp;

	i = -1;
	env_temp = ft_copy_matrix(*env_copy);
	ft_free_matrix(*env_copy, 0);
	(*env_copy) = ft_calloc(ft_strlen_matrix(env_temp) + 2, sizeof(char *));
	while (env_temp[++i] != NULL)
	{
		(*env_copy)[i] = ft_strdup(env_temp[i]);
	}
	(*env_copy)[i] = ft_strjoin("OLDPWD=", ft_get_env("PWD", env_temp));
	ft_free_matrix(env_temp, 0);
}

void	ft_cd(char **matrix, char ***env_copy, t_parameters *p)
{
	char	prv_dir[PATH_MAX];
	int		flag;

	flag = ft_search_oldpwd(*env_copy);
	if (flag == 0)
		ft_create_oldpwd(env_copy);
	getcwd(prv_dir, sizeof(prv_dir));
	if (ft_strlen_matrix(matrix) > 2)
	{
		p->dollar = 1;
		return (ft_putstr_fd("bash: cd: too many arguments\n", 2));
	}
	if (ft_strlen_matrix(matrix) == 1 || (ft_strncmp(matrix[1], "~", 1) == 0 \
		&& ft_strlen(matrix[1]) == 1))
		return (ft_go_to_home(env_copy, prv_dir, p));
	if (ft_strncmp(matrix[1], ".", 1) == 0 && ft_strlen(matrix[1]) == 1)
		return (ft_update_oldpwd(*env_copy));
	if (ft_strncmp(matrix[1], "-", 1) == 0 && ft_strlen(matrix[1]) == 1)
		return (ft_cd_prv_dir(env_copy, flag, prv_dir));
	if (ft_strncmp(matrix[1], "..", 2) == 0 && ft_strlen(matrix[1]) == 2)
		return (ft_previous_dir(prv_dir), ft_update_env(*env_copy, prv_dir));
	if (chdir(matrix[1]) == -1)
		return (ft_cd_error(matrix[1], p), ft_update_env(*env_copy, prv_dir));
	return (ft_update_env(*env_copy, prv_dir));
}

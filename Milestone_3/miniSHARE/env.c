/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 15:48:53 by cciapett          #+#    #+#             */
/*   Updated: 2025/06/14 10:44:04 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_update_env_exe(char *dir, char **env_copy_str, int toggle)
{
	char	*temp;

	if (toggle == 0)
	{
		temp = ft_strjoin("OLDPWD=", dir);
		free(*env_copy_str);
		*env_copy_str = ft_strdup(temp);
		free(temp);
	}
	else
	{
		temp = ft_strjoin("PWD=", dir);
		free(*env_copy_str);
		*env_copy_str = ft_strdup(temp);
		free(temp);
	}
}

void	ft_update_env(char **env_copy, char *prv_dir)
{
	char	curr_dir[PATH_MAX];
	int		i;

	i = 0;
	while (env_copy[i] != NULL)
	{
		if (ft_condition_env(env_copy[i], "OLDPWD") == 0)
		{
			ft_update_env_exe(prv_dir, &env_copy[i], 0);
			break ;
		}
		i++;
	}
	getcwd(curr_dir, sizeof(curr_dir));
	i = -1;
	while (env_copy[++i] != NULL)
	{
		if (ft_condition_env(env_copy[i], "PWD") == 0)
		{
			ft_update_env_exe(curr_dir, &env_copy[i], 1);
			break ;
		}
	}
}

void	ft_update_oldpwd(char **env_copy)
{
	int		i;
	char	*temp;

	i = -1;
	temp = NULL;
	while (env_copy[++i] != NULL)
	{
		if (ft_strncmp("PWD", env_copy[i], ft_strlen("PWD")) == 0 \
		&& env_copy[i][ft_strlen("PWD")] == '=')
			temp = ft_strdup(env_copy[i] + ft_strlen("PWD") + 1);
	}
	i = -1;
	while (env_copy[++i] != NULL)
	{
		if (ft_strncmp("OLDPWD", env_copy[i], ft_strlen("OLDPWD")) == 0 \
		&& env_copy[i][ft_strlen("OLDPWD")] == '=')
		{
			free(env_copy[i]);
			env_copy[i] = ft_strjoin("OLDPWD=", temp);
		}
	}
	free(temp);
}

int	ft_search_equal(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

void	ft_env(char **matrix, char **env_copy, t_parameters *p)
{
	int	i;

	i = 0;
	p->dollar = 0;
	if (ft_strlen_matrix(matrix) > 1)
	{
		ft_putstr_fd("bash: env: too many arguments\n", 2);
		p->dollar = 127;
		return ;
	}
	while (env_copy[i] != NULL)
	{
		if (ft_search_equal(env_copy[i]) == 0)
		{
			ft_putstr_fd(env_copy[i], 1);
			ft_putstr_fd("\n", 1);
		}
		i++;
	}
}

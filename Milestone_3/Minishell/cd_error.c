/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/05 17:25:06 by cciapett          #+#    #+#             */
/*   Updated: 2025/06/14 10:52:37 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cd_home_error(char *s)
{
	char	*tmp;
	char	*tmp2;

	tmp = ft_strjoin("bash: cd: ", s);
	tmp2 = ft_strjoin(tmp, ": No such file or directory\n");
	ft_putstr_fd(tmp2, 2);
	if (tmp != NULL)
		free(tmp);
	if (tmp2 != NULL)
		free(tmp2);
}

char	*ft_search_home(char **env, t_parameters *p)
{
	int		i;
	char	*s;

	s = NULL;
	i = -1;
	while (env[++i] != NULL)
	{
		if (ft_strncmp("HOME=", env[i], ft_strlen("HOME=")) == 0)
		{
			s = &env[i][5];
			break ;
		}
	}
	if (s == NULL)
	{
		ft_putstr_fd("bash: cd: HOME not set\n", 2);
		return (NULL);
	}
	else if (access(s, F_OK) != 0)
	{
		ft_cd_home_error(s);
		p->dollar = 1;
	}
	return (s);
}

void	ft_cd_error(char *matrix1, t_parameters *p)
{
	char	*temp;
	char	*str_err;

	temp = ft_strjoin("cd: not a directory ", matrix1);
	str_err = ft_strjoin(temp, "\n");
	free(temp);
	ft_putstr_fd(str_err, 2);
	free(str_err);
	p->dollar = 1;
}

void	ft_cd_prv_dir(char ***env_copy, int flag, char *prv_dir)
{
	if (flag == 0)
		return (ft_putstr_fd("bash: cd: OLDPWD not set\n", 2));
	ft_putstr_fd(ft_get_env("OLDPWD", *env_copy), 2);
	ft_putstr_fd("\n", 2);
	chdir(ft_get_env("OLDPWD", *env_copy));
	return (ft_update_env(*env_copy, prv_dir));
}

void	ft_go_to_home(char ***env_copy, char *prv_dir, t_parameters *p)
{
	chdir(ft_search_home(*env_copy, p));
	return (ft_update_env(*env_copy, prv_dir));
}

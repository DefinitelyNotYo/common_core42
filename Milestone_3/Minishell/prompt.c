/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:44:39 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/11 14:04:46 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	env_line(char **env, char *path)
{
	int	i;
	int	index;

	i = -1;
	while (env[++i] != NULL)
		if (ft_strncmp(env[i], path, ft_strlen(path)) == 0)
			index = i;
	return (index);
}

int	ft_home_present(char **env)
{
	int	i;

	i = -1;
	while (env[++i] != NULL)
	{
		if (ft_strncmp(env[i], "HOME", ft_strlen("HOME")) == 0 && \
		env[i][ft_strlen("HOME")] == '=')
		{
			if (access(env[i] + ft_strlen("HOME") + 1, F_OK) == 0)
				return (0);
		}
	}
	return (1);
}

char	*ft_prompt(char **env, t_parameters *p)
{
	char	curr_dir[PATH_MAX];

	getcwd(curr_dir, sizeof(curr_dir));
	ft_prompt_exe(p, env);
	if (ft_home_present(env) == 0 && ft_faya(curr_dir, p->pro_home) == 1)
	{
		p->pro_prompt = ft_freejoin(p->pro_prompt, "~");
		if (ft_home(curr_dir) != 0)
		{
			p->pro_tmp = ft_strdup(curr_dir + ft_home(curr_dir));
			p->pro_prompt = ft_freejoin(p->pro_prompt, p->pro_tmp);
		}
	}
	else
	{
		p->pro_tmp = ft_strdup(curr_dir);
		p->pro_prompt = ft_freejoin(p->pro_prompt, p->pro_tmp);
	}
	p->pro_prompt = ft_freejoin(p->pro_prompt, "$ ");
	if (p->pro_home != NULL)
		free(p->pro_home);
	return (free(p->pro_tmp), p->pro_prompt);
}

void	ft_prompt_exe(t_parameters *p, char **env)
{
	p->pro_tmp = NULL;
	p->pro_home = NULL;
	if (ft_home_present(env) == 0)
		p->pro_home = ft_strdup(env[env_line(env, "HOME=")] + 5);
	p->pro_prompt = ft_strjoin(p->user, "@");
	p->pro_prompt = ft_freejoin(p->pro_prompt, p->place);
	p->pro_prompt = ft_freejoin(p->pro_prompt, ":");
}

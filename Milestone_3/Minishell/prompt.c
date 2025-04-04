/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 16:44:39 by yoherfan          #+#    #+#             */
/*   Updated: 2025/04/04 17:50:45 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int env_line(char **env, char *path)
{
    int i;
    int index;
    
    i = -1;
	while (env[++i] != NULL)
		if (ft_strncmp(env[i], path, ft_strlen(path)) == 0)
			index = i;
    return (index);
}

char *ft_prompt(char **env)
{
	char	*temp;
	char	*prompt;
	char	*user;
	char	*path;

	path = ft_strdup(env[env_line(env, "PWD=")]);

	user = ft_strdup(env[env_line(env, "USER=")] + 5);
	
	prompt = ft_strjoin(user, "@");
	
	temp = ft_substr(env[env_line(env, "SESSION_MANAGER=local/")], 22, 6);

	prompt = ft_strjoin(prompt, temp);
	
	prompt = ft_strjoin(prompt, ":");
	
	if (ft_faya(env[env_line(env, "PWD=")], user) == 1)
	{
		prompt = ft_strjoin(prompt, "~");
		if (ft_find_home(path) != 0)
			temp = ft_strdup(env[env_line(env, "PWD=")] + ft_find_home(path));
			prompt = ft_strjoin(prompt, temp);
	}
	else
	{
		temp = ft_strdup(env[env_line(env, "PWD=")] + 4);
		prompt = ft_strjoin(prompt, temp);
	}
	prompt = ft_strjoin(prompt, "$ ");
	return (prompt);
}

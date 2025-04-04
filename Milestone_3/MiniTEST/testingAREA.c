/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testingAREA.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:12:04 by yoherfan          #+#    #+#             */
/*   Updated: 2025/04/04 16:02:39 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// void	ft_execute2(char *cmd, char **env)
// {
// 	t_pathfinder	*p;

// 	if (cmd[0] == '\0' || ft_justspaces(cmd) == 1)
// 		exit(0);
// 	p = ft_calloc(sizeof(t_pathfinder), 1);
// 	p->split_cmd = ft_split(cmd, ' ');
// 	p->i = -1;
// 	p->path = NULL;
// 	while (env[++p->i] != NULL)
// 		if (ft_strncmp(env[p->i], "PATH=", 5) == 0)
// 			p->index = p->i;
// 	p->split_paths = ft_split(&env[p->index][5], ':');
// 	p->i = -1;
// 	while (p->split_paths[++p->i] != NULL)
// 	{
// 		if (p->path != NULL)
// 			free (p->path);
// 		p->temp = ft_strjoin(p->split_paths[p->i], "/");
// 		p->path = ft_strjoin(p->temp, p->split_cmd[0]);
// 		free (p->temp);
// 		printf("%d %s\n", access(p->path, F_OK), p->path);
// 		if (access(p->path, F_OK) == 0)
// 			execve(p->path, p->split_cmd, env);
// 	}
// 	execve(p->split_cmd[0], p->split_cmd, env);
// }

int	ft_faya(char *str, char *faya)
{
	int	i;
	int	j;
	int	faya_lenght;
	
	i = -1;
	j = 0;
	faya_lenght = ft_strlen(faya);
	while(str[++i] != NULL)
	{
		if (str[i] == faya[j])
		{
			if (j == faya_lenght - 1)
				return (1);
			j++;
		}
		else
			j = 0;
	}
	return (0);
}

int	ft_find_home(char *path)
{
	int i;
	int	count;
	
	i = -1;
	count = 0;
	while (path[++i] != NULL)
	{
		if (path[i] == '/')
		{
			count++;
			if (count == 4)
				return (i);
		}
	}
	return (0);
}

char *ft_prompt(char **env)
{
	char	*temp;
	char	*prompt;
	int		i;
	int		index;
	char	*user;
	char	*path;

	i = -1;	
	while (env[++i] != NULL)
		if (ft_strncmp(env[i], "PWD=", 4) == 0)
			index = i;
	path = ft_strdup(env[index]);
	
	i = -1;
	while (env[++i] != NULL)
		if (ft_strncmp(env[i], "USER=", 5) == 0)
			index = i;
	user = ft_strdup(env[index] + 5);
	prompt = ft_strjoin(user, "@");
	
	i = -1;	
	while (env[++i] != NULL)
		if (ft_strncmp(env[i], "SESSION_MANAGER=local/", 22) == 0)
			index = i;	
	temp = ft_substr(env[index], 22, 6);
	prompt = ft_strjoin(prompt, temp);

	prompt = ft_strjoin(prompt, ":");

	i = -1;	
	while (env[++i] != NULL)
		if (ft_strncmp(env[i], "PWD=", 4) == 0)
			index = i;
	if (ft_faya(env[index], user) == 1)
	{
		prompt = ft_strjoin(prompt, "~");
		if (ft_find_home(path) != 0)
			temp = ft_strdup(env[index] + ft_find_home(path));
			prompt = ft_strjoin(prompt, temp);
	}
	else
	{
		temp = ft_strdup(env[index] + 4);
		prompt = ft_strjoin(prompt, temp);
	}
	prompt = ft_strjoin(prompt, "$ ");
	return (prompt);
}

int main(int argc, char **argv, char **env)
{
    char    *str = "test";
	int		id;
	
    while (ft_strncmp(str, "exit", 5) != 0)
    {
        str = readline(ft_prompt(env));
        add_history(str);
    }
}

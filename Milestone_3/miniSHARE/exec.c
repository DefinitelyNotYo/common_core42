/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 15:02:24 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/17 15:22:35 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_execute(t_parameters *pp, char **args, char **env)
{
	t_pathfinder	*p;

	if (args[0] == NULL)
		ft_exec_cleaning(pp);
	p = ft_calloc(sizeof(t_pathfinder), 1);
	p->i = -1;
	p->path = NULL;
	while (env[++p->i] != NULL)
		if (ft_strncmp(env[p->i], "PATH=", 5) == 0)
			p->index = p->i;
	p->split_paths = ft_split(&env[p->index][5], ':');
	p->i = -1;
	while (p->split_paths[++p->i] != NULL)
	{
		if (p->path != NULL)
			free (p->path);
		p->temp = ft_strjoin(p->split_paths[p->i], "/");
		p->path = ft_strjoin(p->temp, args[0]);
		free (p->temp);
		if (access(p->path, F_OK) == 0)
			execve(p->path, args, env);
	}
	execve(args[0], args, env);
	ft_free_exec(p);
}

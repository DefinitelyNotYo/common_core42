/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_manager_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:27:49 by yoherfan          #+#    #+#             */
/*   Updated: 2025/03/25 16:20:56 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_main_process_exe(int *fd)
{
	dup2(fd[0], 0);
	close(fd[0]);
	close(fd[1]);
}

void	ft_cmd_exe(int *files, int *fd, char *cmd, char **env)
{
	close (fd[0]);
	dup2(fd[1], 1);
	close (fd[1]);
	close (files[1]);
	ft_execute(cmd, env, files, 0);
}

void	ft_last_cmd_exe(int *files, char *cmd, char **env)
{
	dup2(files[1], 1);
	close (files[1]);
	ft_execute(cmd, env, files, 0);
}

void	ft_manager(int argc, int *files, char **argv, char **env)
{
	int	i;
	int	fd[2];
	int	id;

	i = 1;
	id = 1;
	while (++i < argc - 1)
	{
		if (i != argc - 2)
			if (pipe(fd) == -1)
				exit(0);
		id = fork();
		if (i < argc - 2 && id == 0)
			ft_cmd_exe(files, fd, argv[i], env);
		else if (i == argc - 2 && id == 0)
			ft_last_cmd_exe(files, argv[i], env);
		else if (i != argc - 2)
			ft_main_process_exe(fd);
	}
	while (wait(&i) > 0)
		;
	ft_clean(files[1], fd);
}

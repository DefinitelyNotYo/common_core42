/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:30:10 by yoherfan          #+#    #+#             */
/*   Updated: 2025/03/31 15:56:14 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_execute(char *cmd, char **env, int *files, int toggle)
{
	t_pathfinder	*p;

	if (cmd[0] == '\0' || ft_justspaces(cmd) == 1)
		exit(0);
	p = ft_calloc(sizeof(t_pathfinder), 1);
	p->split_cmd = ft_split(cmd, ' ');
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
		p->path = ft_strjoin(p->temp, p->split_cmd[0]);
		free (p->temp);
		if (access(p->path, F_OK) == 0)
			execve(p->path, p->split_cmd, env);
	}
	execve(p->split_cmd[0], p->split_cmd, env);
	ft_free_memfd(p, files, toggle);
}

int	main(int argc, char **argv, char **env)
{
	int		files[2];
	int		i;
	char	*temp;

	i = 1;
	temp = NULL;
	if (ft_strncmp(argv[1], "here_doc", 9) == 0)
		ft_here_doc(files, argv, argc);
	else
	{
		if (ft_check_n_args(argc, argv) == 0)
			return (0);
		files[0] = open(argv[1], O_RDONLY);
		files[1] = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	}
	if (ft_check_args(files[0], files[1], argc, argv) == 0)
		return (ft_fast_clean(files[0], files[1]), 0);
	dup2(files[0], 0);
	close(files[0]);
	ft_manager(argc, files, argv, env);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		unlink("here_doc");
	return (0);
}

int	ft_check_args(int file_in, int file_out, int argc, char **argv)
{
	int	toggle;

	if (argc > 3)
	{
		toggle = ft_strncmp(argv[1], "here_doc", 8);
		if (argc > 3 && file_in != -1 && file_out != -1 && toggle != 0)
			return (1);
		else if (argc > 4 && file_in != -1 && file_out != -1 && toggle == 0)
			return (1);
	}
	write(2, "Error: invalid args\n", 20);
	return (0);
}

int	ft_check_last_exe(char *cmd, char **env, int *files)
{
	t_pathfinder	*p;

	if (cmd[0] == '\0')
		return (close(files[0]), close(files[1]), 0);
	p = ft_calloc(sizeof(t_pathfinder), 1);
	ft_jolly_p(p, cmd);
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
		p->path = ft_strjoin(p->temp, p->split_cmd[0]);
		free (p->temp);
		if (access(p->path, F_OK) == 0)
			return (ft_free_memfd(p, files, 0), 1);
	}
	if (access(p->split_cmd[0], F_OK) == 0)
		return (ft_free_memfd(p, files, 0), 1);
	return (ft_free_memfd(p, files, 1), 0);
}

int	ft_check_last(int argc, char **argv, char **env, int *files)
{
	if (ft_check_last_exe(argv[argc - 2], env, files) == 0)
		return (0);
	return (1);
}

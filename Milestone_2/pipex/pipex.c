/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:30:10 by yoherfan          #+#    #+#             */
/*   Updated: 2025/03/18 19:16:20 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//SIGNAL 13 SIGPIPE, DA RISOLVERE?

void ft_execute(char *cmd, char** env)
{
	char **splitted_cmd;
	char **splitted_paths;
	char	*path;
	char	*temp;
	int		index;
	int		i;

	splitted_cmd = ft_split(cmd, ' ');
	i = -1;
	path = NULL;
	while (env[++i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			index = i;
	}
	splitted_paths = ft_split(&env[index][5], ':');
	i = -1;
	while (splitted_paths[++i] != NULL)
	{
		if (path != NULL)
			free (path);
		temp = ft_strjoin(splitted_paths[i], "/");
		path = ft_strjoin(temp, splitted_cmd[0]);
		if (temp)
			free (temp);
		if (access(path, F_OK) == 0)
			execve(path, splitted_cmd, env);
	}
	if (access(splitted_cmd[0], F_OK) == 0)
		execve(splitted_cmd[0], splitted_cmd, env);
	ft_free_matrix(splitted_cmd, 0);
	ft_free_matrix(splitted_paths, 0);
	free(path);
}

int	main(int argc, char **argv, char **env)
{
	int	files[2];
	int	i;
	
	i = 1;
	files[0] = open(argv[1], O_RDONLY);
	files[1] = open(argv[argc - 1], O_WRONLY | O_TRUNC | O_CREAT, 0777);
	printf("\n\n%d\n\n", files[0]);
	printf("\n\n%d\n\n", files[1]);
	if (ft_check_args(files[0], files[1], argc) == 0)
	{
		ft_fast_clean(files[0], files[1]);
		return (0);		
	}
	dup2(files[0], 0);
	ft_manager(argc, files, argv, env);
	return (0);
}

int	ft_check_args(int file_in, int file_out, int argc)
{
	if (argc == 5 && file_in != -1 && file_out != -1)
		return (1);		
	write(1, "Error: invalid args\n", 20);
	return (0);
}
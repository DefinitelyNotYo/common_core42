/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:30:10 by yoherfan          #+#    #+#             */
/*   Updated: 2025/03/17 18:23:11 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//env non viene contato negli argomenti
//il numero di comandi e' uguale ad argc - 3 (che sono il nome dell'eseguibile e i due file)
//sto dando per assunto che il secondo file, quello di output, esiste

void ft_execute(char *cmd, char** env)
{
	char **splitted_cmd;
	char **splitted_paths;
	char	*path;
	int		index;
	int		i;

	splitted_cmd = ft_split(cmd, ' ');
	i = -1;
	while (env[++i] != NULL)
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			index = i;
	}
	splitted_paths = ft_split(&env[index][5], ':');
	i = -1;
	while (splitted_paths[++i] != NULL)
	{
		path = ft_strjoin(splitted_paths[i], "/");
		path = ft_strjoin(path, splitted_cmd[0]);
		if (access(path, F_OK) == 0)
			execve(path, splitted_cmd, env);			
	}
	execve(splitted_cmd[0], splitted_cmd, env);
}

int	main(int argc, char **argv, char **env)
{
    int fd[2];
	int file_in;
	int	file_out;
    int id;
	int	i;
	
	id = 1;
	i = 1;
	file_in = open(argv[1], O_RDONLY);
	file_out = open(argv[argc - 1], O_WRONLY | O_TRUNC);
	dup2(file_in, 0);
	while (++i < argc - 1)
	{
		if (pipe(fd) == -1)
			exit(0);
		id = fork();
		if (i < argc - 2 && id == 0) //dal primo al penultimo comando
		{
			dup2(fd[1], 1);
			ft_clean(file_in, file_out, fd);
			ft_execute(argv[i], env);
			exit(0);
		}
		else if (i == argc - 2 && id == 0) //ultimo comando
		{
			dup2(file_out, 1);
			ft_clean(file_in, file_out, fd);
			ft_execute(argv[i], env);
			exit(0);
		}
		else //processo padre
		{
			wait(NULL);
			close(fd[1]);
			dup2(fd[0], 0);
			close(fd[0]);
		}
	}
	ft_clean(file_in, file_out, fd);
}

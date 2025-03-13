/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 17:30:10 by yoherfan          #+#    #+#             */
/*   Updated: 2025/03/13 18:24:56 by yoherfan         ###   ########.fr       */
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
	char 	*temp;
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
		temp = ft_strjoin(splitted_paths[i], "/");
		path = ft_strjoin(temp, cmd);
		printf("%d", access(path, F_OK));
		printf("%s\n", path);
		if (access(path, F_OK) == 0)
			execve(path, splitted_cmd, env);		
	}
	execve(cmd, splitted_cmd, env);
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

	(void) env;
	if (pipe(fd) == -1)
		exit(0);
	while (++i < argc - 1)
	{
		id = fork();
		if (i == 2 && id == 0)
		{
			// dup2(fd[1], 1);
			ft_execute(argv[i], env);
			exit(0);
		}
		else if (i == 3 && id == 0)
		{
			// dup2(file_out, 1);
			ft_execute(argv[i], env);
			exit(0);
		}
		else
		{
			close(fd[1]);
			dup2(fd[0], 0);
		}
	}
}

// int	main(int argc, char **argv, char **env)
// {
//     int fd[2];
// 	int file_in;
// 	int	file_out;
//     int i;
//     int id;

//     i = 1;
// 	id = 1;
// 	file_in = open(argv[1], O_RDONLY);
// 	file_out = open(argv[argc - 1], O_WRONLY);
	
// 	if (pipe(fd) == -1)
// 		exit(0);
// 	dup2(file_in, 0);
// 	dup2(fd[1], 1);
// 	close(file_in);
//     while (++i < argc - 2)
//     {
// 		id = fork();
// 		close(fd[0]);
// 		close(fd[1]);
// 		close(file_out);

//         if (id == 0) //sono nel ramo dei figli
// 		{
// 			if (i == 2) //sono nel primo figlio
// 			{
// 				close(fd[0]);
// 				close(fd[1]);
// 				close(file_out);			
// 			}
// 			else if (i == argc - 3) //sono nell'ultimo figlio
// 			{
// 				dup2(file_out, 1);
// 				...
// 				close(fd[0]);
// 				close(fd[1]);
// 				close(file_out);
// 			}
// 			else //sono in un figlio centrale
// 			{
// 				dup2(fd[0], 0);
// 				close(fd[0]);
// 				close(fd[1]);
// 				close(file_out);
// 			}
// 		}
//     }
// }
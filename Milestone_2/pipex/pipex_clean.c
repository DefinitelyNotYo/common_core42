/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:18:22 by yoherfan          #+#    #+#             */
/*   Updated: 2025/03/21 15:54:40 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_clean(int file_in, int file_out, int *fd)
{
	close (file_in);
	close (file_out);
	close (fd[0]);
	close (fd[1]);
}

void	ft_fast_clean(int file_in, int file_out)
{
	close (file_in);
	close (file_out);
	exit(0);
}

void	ft_free_mem(char **mat_1, char **mat_2, char *str, t_pathfinder *p)
{
	ft_free_matrix(mat_1, 0);
	ft_free_matrix(mat_2, 0);
	free(str);
	free(p);
}

void	ft_free_memfd(t_pathfinder *p, int *files, int toggle)
{
	ft_free_matrix(p->split_cmd, 0);
	ft_free_matrix(p->split_paths, 0);
	free(p->path);
	free(p);
	if (toggle == 1)
	{
		close(files[0]);
		close(files[1]);
	}
}

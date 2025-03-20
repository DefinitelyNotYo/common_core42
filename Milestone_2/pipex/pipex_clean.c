/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:18:22 by yoherfan          #+#    #+#             */
/*   Updated: 2025/03/20 16:02:06 by yoherfan         ###   ########.fr       */
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

void	ft_free_memory(char **matrix_1, char **matrix_2, char *str)
{
	ft_free_matrix(matrix_1, 0);
	ft_free_matrix(matrix_2, 0);
	free(str);
}

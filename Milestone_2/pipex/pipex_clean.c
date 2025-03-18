/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/18 16:18:22 by yoherfan          #+#    #+#             */
/*   Updated: 2025/03/18 18:08:35 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void ft_clean(int file_in, int file_out, int *fd)
{
	close (file_in);
	close (file_out);
	close (fd[0]);
	close (fd[1]);
}

void    ft_fast_clean(int file_in, int file_out)
{
    close (file_in);
	close (file_out);
    exit(0);
}
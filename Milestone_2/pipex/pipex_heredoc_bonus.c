/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_heredoc_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 18:44:22 by yoherfan          #+#    #+#             */
/*   Updated: 2025/03/27 15:40:18 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_here_doc(int *files, char **argv, int argc)
{
	char	*temp;

	files[0] = open(argv[1], O_RDWR | O_APPEND | O_CREAT, 0777);
	write(1, "> ", 2);
	temp = get_next_line(0);
	while (temp != NULL)
	{
		if (ft_strncmp(temp, argv[2], ft_strlen(argv[2])) == 0 && \
			ft_strlen(argv[2]) == ft_strlen(temp) - 1)
		{
			free(temp);
			break ;
		}
		ft_putstr_fd(temp, files[0]);
		free (temp);
		write(1, "> ", 2);
		temp = get_next_line(0);
	}
	close (files[0]);
	files[0] = open(argv[1], O_RDWR | O_CREAT, 0777);
	files[1] = open(argv[argc - 1], O_WRONLY | O_APPEND | O_CREAT, 0777);
}

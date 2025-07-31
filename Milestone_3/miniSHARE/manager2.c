/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manager2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:35:56 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/17 14:54:50 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_parse_manager_exe_2(t_parameters *p, char **args, int len, int *i)
{
	i[0] = -1;
	ft_free_matrix(args, 0);
	while (++i[0] < len)
	{
		if (p->flag_heredoc == 1)
			break ;
		if (pipe(p->fd) == -1)
			exit(0);
		exec_manager(&p->p_args[i[0]], p, i[0]);
		close(p->fd[0]);
		close(p->fd[1]);
	}
}

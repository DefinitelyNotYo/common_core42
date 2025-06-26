/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_setup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/09 15:10:01 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/17 17:56:32 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_main_setup(t_parameters *p, int argc, char **argv, char **env)
{
	(void)argc;
	(void)argv;
	p->str = ft_strdup("test");
	p->prompt = NULL;
	p->dollar = 0;
	p->tmp = ft_strdup("temp");
	p->env_copy = ft_copy_matrix(env);
	p->read_0 = dup(0);
	p->write_1 = dup(1);
	p->flag_unset = 0;
	p->pid_child = 0;
	p->flag_heredoc = 0;
	p->user = ft_strdup(env[env_line(env, "USER=")] + 5);
	p->place = ft_substr(env[env_line(env, "SESSION_MANAGER=local/")], 22, 6);
	p->lastchild = 0;
}

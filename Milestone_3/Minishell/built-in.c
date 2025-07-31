/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 15:36:20 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/13 17:15:12 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_is_built_in(char **args)
{
	if (!args[0])
		return (0);
	if (ft_strncmp(args[0], "echo", 4) == 0 && \
		ft_strlen(args[0]) == ft_strlen("echo"))
		return (1);
	if (ft_strncmp(args[0], "cd", 2) == 0 && \
		ft_strlen(args[0]) == ft_strlen("cd"))
		return (2);
	if (ft_strncmp(args[0], "pwd", 3) == 0 && \
		ft_strlen(args[0]) == ft_strlen("pwd"))
		return (3);
	if (ft_strncmp(args[0], "export", 6) == 0 && \
		ft_strlen(args[0]) == ft_strlen("export"))
		return (4);
	if (ft_strncmp(args[0], "unset", 5) == 0 && \
		ft_strlen(args[0]) == ft_strlen("unset"))
		return (5);
	if (ft_strncmp(args[0], "env", 3) == 0 && \
		ft_strlen(args[0]) == ft_strlen("env"))
		return (6);
	if (ft_strncmp(args[0], "exit", 4) == 0 && \
		ft_strlen(args[0]) == ft_strlen("exit"))
		return (7);
	return (ft_include_built_in(args));
}

int	ft_include_built_in(char **args)
{
	if (ft_faya(args[0], "echo") && access(args[0], F_OK) == 0)
		return (1);
	if (ft_faya(args[0], "cd") && access(args[0], F_OK) == 0)
		return (2);
	if (ft_faya(args[0], "pwd") && access(args[0], F_OK) == 0)
		return (3);
	if (ft_faya(args[0], "export") && access(args[0], F_OK) == 0)
		return (4);
	if (ft_faya(args[0], "unset") && access(args[0], F_OK) == 0)
		return (5);
	if (ft_faya(args[0], "env") && access(args[0], F_OK) == 0)
		return (6);
	if (ft_faya(args[0], "exit") && access(args[0], F_OK) == 0)
		return (7);
	return (0);
}

void	ft_built_in_exe(char **args, int flag, t_parameters *p)
{
	if (flag == 1)
		ft_echo(args, p);
	if (flag == 2)
	{
		ft_cd(args, &p->env_copy, p);
		if (p->prompt != NULL)
			free (p->prompt);
		p->prompt = ft_prompt(p->env_copy, p);
	}
	if (flag == 3)
		ft_pwd(p);
	if (flag == 4)
		ft_export(args, &p->env_copy, p);
	if (flag == 5)
		ft_unset(args, &p->env_copy, &p);
	if (flag == 6)
		ft_env(args, p->env_copy, p);
	if (flag == 7)
		ft_exit(args, p);
}

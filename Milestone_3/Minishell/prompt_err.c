/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt_err.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 17:04:25 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/16 16:18:05 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	prompt_err_manager(char *prompt)
{
	if (check_redir(prompt, '>') == 0)
		return (0);
	if (check_redir(prompt, '<') == 0)
		return (0);
	if (check_pipes(prompt) == 0)
		return (0);
	return (1);
}

int	check_redir(char *prompt, char c)
{
	int	i;
	int	flags[3];

	i = -1;
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	check_redir_exe(prompt, flags, i, c);
	if (flags[1] > 0 || flags[2] == 1)
		return (0);
	return (1);
}

void	ft_put_fd_err(char *str, int toggle)
{
	if (toggle == 1)
	{
		write(2, "bash: ", 6);
		ft_putstr_fd(str, 2);
		write(2, ": Is a directory\n", 17);
	}
	else if (toggle == 0)
	{
		write(2, "bash: ", 6);
		ft_putstr_fd(str, 2);
		write(2, ": No such file or directory\n", 28);
	}
}

void	check_redir_exe(char *prompt, int *flags, int i, char c)
{
	while (prompt[++i] != '\0')
	{
		if ((prompt[i] == '>' && prompt[i + 1] == '<') || \
			(prompt[i + 1] == '>' && prompt[i] == '<'))
			flags[2] = 1;
		else if (prompt[i] == '\'' && flags[0] == 0)
			flags[0] = 1;
		else if (prompt[i] == '\'' && flags[0] == 1)
			flags[0] = 0;
		else if (prompt[i] == '\"' && flags[0] == 0)
			flags[0] = 2;
		else if (prompt[i] == '\"' && flags[0] == 2)
			flags[0] = 0;
		else if (prompt[i] == c && flags[0] == 0)
			flags[1]++;
		else
		{
			if (flags[1] > 2)
				flags[2] = 1;
			else if (prompt[i] != ' ' && prompt[i] != '\"' && \
				prompt[i] != '\'' && (flags[1] == 2 || flags[1] == 1))
				flags[1] = 0;
		}
	}
}

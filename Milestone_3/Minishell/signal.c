/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 15:35:39 by cciapett          #+#    #+#             */
/*   Updated: 2025/06/17 13:49:21 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sigint(int sig)
{
	g_var_signal = sig + 130;
	write(STDOUT_FILENO, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	child_sigint(int sig)
{
	g_var_signal = sig + 128;
	write(2, "\n", 1);
	rl_on_new_line();
	rl_replace_line("", 0);
}

void	child_sigquit(int sig)
{
	(void)sig;
	g_var_signal = 131;
	write(2, "Quit (core dumped)\n", 19);
	rl_on_new_line();
	rl_replace_line("", 0);
}

void	heredoc_sigint(int sig)
{
	g_var_signal = sig + 128;
	write(2, "\n", 1);
	close(0);
}

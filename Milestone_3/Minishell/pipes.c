/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 15:33:56 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/14 12:11:47 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_pipes(char *prompt)
{
	int	i;
	int	flags[3];
	int	count;

	i = -1;
	count = 0;
	flags[1] = 0;
	flags[2] = 0;
	while (prompt[++i] != '\0')
	{
		if (flags[1] == 0 && flags[2] == 0 && prompt[i] == '\'')
			flags[1] = 1;
		else if (flags[2] == 0 && flags[1] == 0 && prompt[i] == '"')
			flags[2] = 1;
		else if (flags[1] == 1 && prompt[i] == '\'')
			flags[1] = 0;
		else if (flags[2] == 1 && prompt[i] == '"')
			flags[2] = 0;
		else if (flags[2] == 0 && flags[1] == 0 && prompt[i] == '|')
			count++;
	}
	return (count);
}

int	check_pipes(char *prompt)
{
	int	par[3];

	par[0] = -1;
	par[1] = 0;
	par[2] = 0;
	while (prompt[++par[0]] != '\0')
	{
		if (prompt[par[0]] == '\'' && par[1] == 0)
			par[1] = 1;
		else if (prompt[par[0]] == '\'' && par[1] == 1)
			par[1] = 0;
		else if (prompt[par[0]] == '\"' && par[1] == 0)
			par[1] = 2;
		else if (prompt[par[0]] == '\"' && par[1] == 2)
			par[1] = 0;
		else if (prompt[par[0]] == '|' && par[2] == 1)
			return (0);
		else if (prompt[par[0]] != '|' && prompt[par[0]] != ' ')
			par[2] = 0;
		else if (prompt[par[0]] == '|' && par[1] == 0)
			par[2] = 1;
	}
	if (par[2] == 1)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:57:49 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/06 14:59:51 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	get_last_quote(char *prompt)
{
	int	i;
	int	index;
	int	flag;

	i = -1;
	flag = 0;
	while (prompt[++i] != '\0')
	{
		if (flag == 0 && prompt[i] == '\'')
			flag = 1;
		if (flag == 0 && prompt[i] == '"')
			flag = 2;
		if (flag == 1 && prompt[i] == '\'')
			index = i;
		if (flag == 2 && prompt[i] == '"')
			index = i;
	}
	return (index);
}

char	*prompt_clear(char *prompt)
{
	char	*tmp;
	int		flag;
	int		i[2];

	i[0] = -1;
	flag = 0;
	i[1] = 0;
	tmp = ft_calloc(1, ft_strlen(prompt) + 1);
	while (prompt[++i[0]] != '\0')
	{
		if (flag == 0 && prompt[i[0]] == '\'')
			flag = 1;
		else if (flag == 0 && prompt[i[0]] == '"')
			flag = 2;
		else if (flag == 1 && prompt[i[0]] == '\'')
			flag = 0;
		else if (flag == 2 && prompt[i[0]] == '"')
			flag = 0;
		else
		{
			tmp[i[1]] = prompt[i[0]];
			i[1]++;
		}
	}
	return (free (prompt), tmp);
}

int	check_n_q(char *prompt, t_parameters *p)
{
	int	i;
	int	flags[3];

	i = -1;
	flags[1] = 0;
	flags[2] = 0;
	while (prompt[++i] != '\0')
	{
		if (flags[1] == 0 && flags[2] == 0 && prompt[i] == '\'')
			flags[1] = 1;
		else if (flags[2] == 0 && flags[1] == 0 && prompt[i] == '\"')
			flags[2] = 1;
		else if (flags[1] == 1 && prompt[i] == '\'')
			flags[1] = 0;
		else if (flags[2] == 1 && prompt[i] == '\"')
			flags[2] = 0;
	}
	if (flags[1] == 1 || flags[2] == 1)
	{
		ft_putstr_fd("error: invalid number of quotes\n", 2);
		p->dollar = 127;
		return (1);
	}
	return (0);
}

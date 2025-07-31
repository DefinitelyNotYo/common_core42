/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 16:20:48 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/13 17:13:33 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_next_end(const char *s, char c)
{
	int		i;
	int		flag_qq;
	int		flag_q;

	i = 0;
	flag_qq = 0;
	flag_q = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == '"' && flag_qq == 0 && flag_q == 0)
			flag_qq = 1;
		else if (s[i] == '\'' && flag_qq == 0 && flag_q == 0)
			flag_q = 1;
		else if (s[i] == '\'' && flag_qq == 0 && flag_q == 1)
			flag_q = 0;
		else if (s[i] == '"' && flag_qq == 1 && flag_q == 0)
			flag_qq = 0;
		if (s[i] == c && flag_qq == 0 && flag_q == 0)
			return (i);
		i++;
	}
	return (i);
}

//param[0] -> i			param[1] -> flag_q
//param[2] -> flag_Q	param[3] -> toggle
//param[4] -> count;
int	count_arguments(char const *s, char c)
{
	int	param[5];

	set_arguments(param);
	while (s[++param[0]] != '\0')
	{
		if (s[param[0]] == '"' && param[1] == 0 && param[2] == 0)
			param[2] = 1;
		else if (s[param[0]] == '\'' && param[1] == 0 && param[2] == 0)
			param[1] = 1;
		else if (s[param[0]] == '"' && param[2] == 1 && param[1] == 0)
			param[2] = 0;
		else if (s[param[0]] == '\'' && param[1] == 1 && param[2] == 0)
			param[1] = 0;
		if (param[1] == 0 && param[2] == 0)
		{
			if (s[param[0]] == c && param[3] == 1)
				param[3] = 0;
			if (s[param[0]] != c && param[3] == 0)
			{
				param[3] = 1;
				param[4]++;
			}
		}
	}
	return (param[4]);
}

void	set_arguments(int *param)
{
	param[4] = 0;
	param[3] = 0;
	param[2] = 0;
	param[1] = 0;
	param[0] = -1;
}

//param[0] -> i		param[1] -> j
//param[2] -> k		param[3] -> flag_Q
//param[4] -> flag_q
char	**ft_split_args(char *s, char c)
{
	char	**matrix;
	int		param[5];

	param[0] = 0;
	param[1] = 0;
	matrix = (char **)ft_calloc((count_arguments(s, c) + 1), sizeof(char *));
	if (!matrix)
		return (NULL);
	while (param[1] < count_arguments(s, c))
	{
		param[3] = 0;
		param[4] = 0;
		param[2] = 0;
		while (s[param[0]] == c)
			param[0]++;
		matrix[param[1]] = ft_calloc(ft_next_end(&s[param[0]], c) + 1, 1);
		if (!matrix[param[1]])
			return (ft_free_matrix(matrix, param[1]), NULL);
		while (s[param[0]] != '\0')
			if (ft_split_args_exe(s, matrix, param, c) == 1)
				break ;
		matrix[param[1]++][param[2]] = '\0';
	}
	return (matrix[param[1]] = NULL, matrix);
}

//param[0] -> i		param[1] -> j
//param[2] -> k		param[3] -> flag_Q
//param[4] -> flag_q
int	ft_split_args_exe(char *s, char **matrix, int *param, char c)
{
	if (param[4] == 0 && param[3] == 0 && s[param[0]] == '\'')
		param[4] = 1;
	else if (param[4] == 0 && param[3] == 0 && s[param[0]] == '"')
		param[3] = 1;
	else if (param[4] == 1 && param[3] == 0 && s[param[0]] == '\'')
		param[4] = 0;
	else if (param[4] == 0 && param[3] == 1 && s[param[0]] == '"')
		param[3] = 0;
	if (s[param[0]] == c && param[3] == 0 && param[4] == 0)
		return (1);
	matrix[param[1]][param[2]++] = s[param[0]++];
	return (0);
}

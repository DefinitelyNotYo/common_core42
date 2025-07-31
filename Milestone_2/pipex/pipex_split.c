/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:12:55 by yoherfan          #+#    #+#             */
/*   Updated: 2025/03/21 13:45:32 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free_matrix(char **matrix, int i)
{
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free (matrix);
}

int	ft_next_delim_index(const char *s, char c)
{
	int	i;

	i = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (i);
}

int	count_words(char const *s, char c)
{
	int	i;
	int	toggle;
	int	count;

	count = 0;
	i = -1;
	toggle = 0;
	while (s[++i] != '\0')
	{
		if (s[i] == c && toggle == 1)
			toggle = 0;
		if (s[i] != c && toggle == 0)
		{
			toggle = 1;
			count++;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	char	**matrix;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	matrix = (char **)ft_calloc((count_words(s, c) + 1), sizeof(char *));
	if (!matrix)
		return (NULL);
	while (j < count_words(s, c))
	{
		k = 0;
		while (s[i] == c)
			i++;
		matrix[j] = ft_calloc(ft_next_delim_index(&s[i], c) + 1, 1);
		if (!matrix[j])
			return (ft_free_matrix(matrix, j), NULL);
		while (s[i] != '\0' && s[i] != c)
			matrix[j][k++] = s[i++];
		matrix[j++][k] = '\0';
	}
	return (matrix[j] = NULL, matrix);
}

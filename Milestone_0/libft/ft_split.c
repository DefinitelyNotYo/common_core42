/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 18:45:43 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/05 15:49:04 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_matrix(char **matrix, int i)
{
	while (i >= 0)
	{
		free(matrix[i]);
		i--;
	}
	free (matrix);
}

static int	ft_next_delim_index(const char *s, char c)
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

static int	count_words(char const *s, char c)
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

/*
int main()
{
	char	**matrix;
	matrix = ft_split(",,,,ci,a,,,,,,,,,,,,,,,o,,,,", ',');
	printf("%s\n", matrix[0]);
	printf("%s\n", matrix[1]);
	printf("%s\n", matrix[2]);
	ft_free_matrix(matrix, count_words(",,,,ci,a,,,,,,,,,,,,,,,o,,,,", ','));
}*/
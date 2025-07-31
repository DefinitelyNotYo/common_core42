/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:21:01 by yoherfan          #+#    #+#             */
/*   Updated: 2025/07/31 17:02:30 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	remove_newlines(t_input *input)
{
    int     i;
    int     j;
    char    *clone;

	i = -1;
	while (++i < input->file_rows)
	{
		j = -1;
		clone = ft_strdup(input->file[i]);
		free(input->file[i]);
		if (clone[ft_strlen(clone) - 1] != '\n')
			input->file[i] = ft_substr(clone, 0, ft_strlen(clone));
		else
			input->file[i] = ft_substr(clone, 0, ft_strlen(clone) - 1);
    }
}

int		find_char(char *str, char *chars, int flag)
{
	int	i;
	int	j;
	int	toggle;

	i = -1;
	toggle = 0;
	while (str[++i] != '\0')
	{
		j = -1;
		if (flag == 1)
			toggle = 0;
		while(chars[++j] != '\0')
		{
			if (str[i] == chars[j])
				toggle = 1;
		}
		if (flag == 1)
			if (toggle == 0)
				return (0);
	}
	return (toggle);
}

char	*ft_strdup2(char *s, int len)
{
	char	*str;
	int		i;

	if (s == NULL)
		return (NULL);
	i = -1;
	str = (char *)ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (NULL);
	while (s[++i] != '\0')
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}

char	**ft_split2(char const *s, char c)
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
		while (s[i] == c || s[i] == ' ')
			i++;
		matrix[j] = ft_calloc(ft_next_delim_index(&s[i], c) + 1, 1);
		if (!matrix[j])
			return (ft_free_matrix_split(matrix, j), NULL);
		while (s[i] != '\0' && s[i] != c && s[i] != ' ')
			matrix[j][k++] = s[i++];
		matrix[j++][k] = '\0';
	}
	return (matrix[j] = NULL, matrix);
}

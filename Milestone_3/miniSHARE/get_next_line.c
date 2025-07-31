/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:35:47 by yoherfan          #+#    #+#             */
/*   Updated: 2025/05/13 18:45:25 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*find_line(char *str)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	result = ft_calloc(i + 2, 1);
	i++;
	while (j < i)
	{
		result[j] = str[j];
		j++;
	}
	result[j] = '\0';
	return (result);
}

char	*solve_problems(char *buffer)
{
	if (ft_strlen(buffer) > 0)
		return (buffer);
	else
	{
		free (buffer);
		return (NULL);
	}
}

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*temp;
	char		*result;
	char		*buffer;

	buffer = ft_calloc(1, 1);
	if (fd < 0)
		return (NULL);
	while (check_newline(buffer) == 0)
	{
		temp = ft_calloc(1 + 1, 1);
		bytes_read = read(fd, temp, 1);
		if (bytes_read < 1)
			return (free(temp), solve_problems(buffer));
		buffer = ft_strjoin_g(buffer, temp);
		free(temp);
	}
	result = find_line(buffer);
	return (free(buffer), result);
}

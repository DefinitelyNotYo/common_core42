/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:35:47 by yoherfan          #+#    #+#             */
/*   Updated: 2025/02/19 14:47:15 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*find_scrap(char *str)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!str)
		return (NULL);
	while (str[i] != '\n')
		i++;
	i++;
	result = ft_calloc(ft_strlen(str) - i + 1, 1);
	while (str[i] != '\0')
	{
		result[j] = str[i];
		j++;
		i++;
	}
	result[j] = '\0';
	return (result);
}

char	*solve_problems(char *buffer, char **scrap)
{
	*scrap = NULL;
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
	char static	*scrap;

	if (scrap == NULL)
		scrap = ft_calloc(1, 1);
	if (scrap != NULL)
		buffer = ft_strdup(scrap);
	free (scrap);
	if (BUFFER_SIZE < 1 || fd < 0)
		return (free(buffer), NULL);
	while (check_newline(buffer) == 0)
	{
		temp = ft_calloc(BUFFER_SIZE + 1, 1);
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read < 1)
			return (free(temp), solve_problems(buffer, &scrap));
		buffer = ft_strjoin(buffer, temp);
		free(temp);
	}
	scrap = find_scrap(buffer);
	result = find_line(buffer);
	return (free(buffer), result);
}

// int main()
// {
//     int fd = open("./maps/map_0.ber", O_RDONLY);
// 	char *line = get_next_line(fd);
// 	printf("%s", line);
// 	while(line)
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 		printf("%s", line);
// 	}
// 	close(fd);
// }
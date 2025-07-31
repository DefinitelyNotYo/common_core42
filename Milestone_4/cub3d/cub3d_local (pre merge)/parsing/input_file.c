/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 16:18:22 by yoherfan          #+#    #+#             */
/*   Updated: 2025/07/31 17:02:45 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_get_file_rows(int fd)
{
	char	*map;
	int		i;

	i = 0;
	map = get_next_line(fd);
	free(map);
	while (map)
	{
		map = get_next_line(fd);
		i++;
		free (map);
	}
	return (i);
}

char	**ft_get_file(int fd, int dim)
{
	char	*line;
	char	**map;
	int		i;

	map = (char **)ft_calloc(sizeof(char *), dim + 1);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i] = ft_strdup(line);
		free (line);
		line = get_next_line(fd);
		i++;
	}
	map[i] = NULL;
	return (map);
}

void	ft_get_map(t_input *input, int *indxs)
{
	int	i;
	int	len;
	
	i = -1;
	len = -1;
	input->map = (char **)ft_calloc(sizeof (char *), input->file_rows - indxs[2] + 1);
	while (++i < input->file_rows - indxs[2])
		if ((int)ft_strlen(input->file[i + indxs[2]]) > len)
			len = ft_strlen(input->file[i + indxs[2]]);
	i = -1;
	input->map_len = len;
	while (++i < input->file_rows - indxs[2])
		input->map[i] = ft_strdup2(input->file[i + indxs[2]], len);
	input->map[i] = NULL;
}

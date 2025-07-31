/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 14:58:51 by yoherfan          #+#    #+#             */
/*   Updated: 2025/03/04 17:11:23 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_get_map_rows(int fd)
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

char	**ft_get_map(int fd, int dim)
{
	char	*line;
	char	**map;
	int		i;

	map = (char **)ft_calloc(sizeof(char *), dim);
	i = 0;
	line = get_next_line(fd);
	while (line)
	{
		map[i] = ft_strdup(line);
		free (line);
		line = get_next_line(fd);
		i++;
	}
	return (map);
}

void	ft_draw_map(void *params)
{
	t_param	*dummy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	dummy = (t_param *)params;
	while (i < dummy->map_rows)
	{
		j = 0;
		while (dummy->map[i][j] != '\0' && dummy->map[i][j] != '\n')
		{
			ft_pick_objects(dummy->map[i][j], params, i, j);
			j++;
		}
		i++;
	}
}

void	ft_pick_objects(char point, void *params, int j, int i)
{
	t_param	*dummy;

	dummy = (t_param *)params;
	if (point == '0')
		mlx_put_image_to_window(\
			dummy->session, dummy->window, dummy->img[0].img, 21 * i, 21 * j);
	if (point == '1')
		mlx_put_image_to_window(\
			dummy->session, dummy->window, dummy->img[1].img, 21 * i, 21 * j);
	if (point == 'C')
		mlx_put_image_to_window(\
			dummy->session, dummy->window, dummy->img[2].img, 21 * i, 21 * j);
	if (point == 'E')
		mlx_put_image_to_window(\
			dummy->session, dummy->window, dummy->img[3].img, 21 * i, 21 * j);
	if (point == 'P')
		ft_pick_pov(dummy, j, i);
}

void	ft_pick_pov(t_param *dummy, int j, int i)
{
	if (dummy->pc.pov == 'f' && dummy->pc.on_exit == 1)
		mlx_put_image_to_window(\
			dummy->session, dummy->window, dummy->img[8].img, 21 * i, 21 * j);
	else if (dummy->pc.pov == 'b' && dummy->pc.on_exit == 1)
		mlx_put_image_to_window(\
			dummy->session, dummy->window, dummy->img[9].img, 21 * i, 21 * j);
	else if (dummy->pc.pov == 'r' && dummy->pc.on_exit == 1)
		mlx_put_image_to_window(\
			dummy->session, dummy->window, dummy->img[10].img, 21 * i, 21 * j);
	else if (dummy->pc.pov == 'l' && dummy->pc.on_exit == 1)
		mlx_put_image_to_window(\
			dummy->session, dummy->window, dummy->img[11].img, 21 * i, 21 * j);
	else if (dummy->pc.pov == 'f')
		mlx_put_image_to_window(\
			dummy->session, dummy->window, dummy->img[4].img, 21 * i, 21 * j);
	else if (dummy->pc.pov == 'b')
		mlx_put_image_to_window(\
			dummy->session, dummy->window, dummy->img[5].img, 21 * i, 21 * j);
	else if (dummy->pc.pov == 'r')
		mlx_put_image_to_window(\
			dummy->session, dummy->window, dummy->img[6].img, 21 * i, 21 * j);
	else if (dummy->pc.pov == 'l')
		mlx_put_image_to_window(\
			dummy->session, dummy->window, dummy->img[7].img, 21 * i, 21 * j);
}

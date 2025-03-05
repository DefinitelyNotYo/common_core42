/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_clean.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:02:22 by yoherfan          #+#    #+#             */
/*   Updated: 2025/03/04 17:17:14 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_clean_board(void *params)
{
	t_param	*dummy;
	int		i;

	i = -1;
	dummy = (t_param *)params;
	while (++i < 12)
		mlx_destroy_image(dummy->session, dummy->img[i].img);
	free(dummy->img);
	mlx_destroy_window(dummy->session, dummy->window);
	mlx_destroy_display(dummy->session);
	free(dummy->session);
	ft_clean_map(dummy->map, dummy->map_rows);
	exit (0);
	return (0);
}

void	ft_clean_map(char **map, int map_rows)
{
	int	i;

	i = -1;
	while (++i < map_rows)
		free (map[i]);
	free (map);
}

int	ft_clean_board2(void *params)
{
	t_param	*dummy;
	int		i;

	i = -1;
	dummy = (t_param *)params;
	dummy->moves++;
	while (++i < 12)
		mlx_destroy_image(dummy->session, dummy->img[i].img);
	free(dummy->img);
	mlx_destroy_window(dummy->session, dummy->window);
	mlx_destroy_display(dummy->session);
	free(dummy->session);
	ft_clean_map(dummy->map, dummy->map_rows);
	ft_put_move(params, 0);
	exit (0);
	return (0);
}

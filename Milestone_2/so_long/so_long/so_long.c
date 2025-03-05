/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:30:48 by yoherfan          #+#    #+#             */
/*   Updated: 2025/03/04 15:45:03 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_setup(char *line, t_param *params)
{
	int	fd;

	fd = open(line, O_RDONLY);
	(*params).map = ft_get_map(fd, (*params).map_rows);
	close(fd);
	ft_check_map(params);
	ft_set_character(params);
	fd = open(line, O_RDONLY);
	ft_clean_map((*params).map, (*params).map_rows);
	(*params).map = ft_get_map(fd, (*params).map_rows);
	close(fd);
	ft_set_character(params);
}

int	main(int argc, char **argv)
{
	t_param	params;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	params.map_rows = ft_get_map_rows(fd);
	if (ft_check_format(argv[1]) == 0 || fd == -1 || params.map_rows == 0 \
		|| argc != 2)
	{
		write(1, "Error\nInvalid map\n", 18);
		return (0);
	}
	close(fd);
	ft_setup(argv[1], &params);
	params.img = malloc(sizeof(t_data) * 12);
	params.session = mlx_init();
	params.window = mlx_new_window(params.session, 21 * (ft_strlen(\
		params.map[0]) - 1), 21 * params.map_rows, "So_long");
	ft_set_img(&params);
	ft_draw_map(&params);
	mlx_hook(params.window, 17, 0, ft_clean_board, &params);
	mlx_hook(params.window, KeyPress, KeyPressMask, ft_manager, &params);
	mlx_loop(params.session);
	return (0);
}

int	ft_manager(int key, void *params)
{
	t_param	*dummy;

	dummy = (t_param *)params;
	if (XK_Escape == key)
		ft_clean_board(params);
	if (key == XK_Up || key == XK_Down || key == XK_Left || key == XK_Right)
		ft_move_manager(key, params);
	return (0);
}

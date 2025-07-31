/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:08:40 by cciapett          #+#    #+#             */
/*   Updated: 2025/07/30 18:17:26 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_exit(int key, void *arg)
{
    t_window   *win;
    win = (t_window *)arg;

    if (key == XK_Escape)
    {
        mlx_destroy_window(win->mlx, win->window);
        mlx_destroy_display(win->mlx);
        exit(0);
	    return (0);
    }
	return (0);
}

int ft_clean(void *arg)
{
    t_window	*win;

	win = (t_window *)arg;
	mlx_destroy_window(win->mlx, win->window);
	mlx_destroy_display(win->mlx);
	exit(0);
	return (0);
}

int main(int argc, char **argv)
{
    t_input		input;
    // t_window    win;
    
    parse_cub3d(argc, argv, &input);
    // ft_read_map(&input);
    // win.mlx = mlx_init();
    // win.window = mlx_new_window(win.mlx, WIDTH, HEIGHT, "giochino");
    // mlx_hook(win.window, KeyPress, KeyPressMask, ft_exit, &win);
	// mlx_hook(win.window, 17, 0, ft_clean, &win);

    // mlx_loop(win.mlx);
    
}

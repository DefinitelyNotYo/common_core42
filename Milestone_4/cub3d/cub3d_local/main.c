/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/18 16:08:40 by cciapett          #+#    #+#             */
/*   Updated: 2025/07/31 17:40:51 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void    ft_moves(int key, t_win *win)
{
    float   temp_x;
    float   temp_y;
    int     toggle;

    temp_x = 0;
    temp_y = 0;
    toggle = 0;
    if (key == XK_Up)
    {
        temp_x = win->pc->posX;
        temp_y = win->pc->posY - 0.5;
        if (ft_check_map((int)temp_x, (int)temp_y, win->input, win->pc) == 1)
        {
            // win->pc->posY += 0.5;
            toggle = 1;
            // return ;
        }
        if (toggle == 0)
            win->pc->posY -= 0.5;
    }
    else if (key == XK_Down)
    {
        temp_x = win->pc->posX;
        temp_y= win->pc->posY + 0.5;
        if (ft_check_map((int)temp_x, (int)temp_y, win->input, win->pc) == 1)
        {
            // win->pc->posY -= 0.5;
            toggle = 1;
            // return ;
        }
        if (toggle == 0)
            win->pc->posY += 0.5;
    }
    else if (key == XK_Left)
    {
        temp_x = win->pc->posX - 0.5;
        temp_y = win->pc->posY;
        if (ft_check_map((int)temp_x, (int)temp_y, win->input, win->pc) == 1)
        {
            // win->pc->posX += 0.5;
            toggle = 1;
            // return ;
        }
        if (toggle == 0)
            win->pc->posX -= 0.5;
    }
    else if (key == XK_Right)
    {
        temp_x = win->pc->posX + 0.5;
        temp_y = win->pc->posY;
        if (ft_check_map((int)temp_x, (int)temp_y, win->input, win->pc) == 1)
        {
            // win->pc->posX -=0.5;
            toggle = 1;
            // return ;
        }
        if (toggle == 0)
            win->pc->posX += 0.5;
            
    }
    ft_rays(win->pc, win->input, win);
    mlx_put_image_to_window(win->mlx, win->window, win->img, 0, 0);
}

int ft_press_key(int key, void *arg)
{
    t_win   *win;
    win = (t_win *)arg;

    if (key == XK_Escape)
    {
        mlx_destroy_window(win->mlx, win->window);
        mlx_destroy_display(win->mlx);
        exit(0);
	    return (0);
    }
    if (key == XK_Up || key == XK_Down || key == XK_Left || key == XK_Right)
    {
        // printf("Movimento\n");
        ft_moves(key, win);
    }
	return (0);
}

int ft_clean(void *arg)
{
    t_win	*win;

	win = (t_win *)arg;
	mlx_destroy_window(win->mlx, win->window);
	mlx_destroy_display(win->mlx);
	exit(0);
	return (0);
}

int main(int argc, char **argv)
{
    t_input		input;
    t_win       win;
    t_pc        pc;

    parse_cub3d(argc, argv, &input);
    win.pc = &pc;
    win.input = &input;
    ft_read_map(&input, &pc);
    win.mlx = mlx_init();
    win.window = mlx_new_window(win.mlx, WIDTH, HEIGHT, "giochino");
    win.img = mlx_new_image(win.mlx, WIDTH, HEIGHT);
    win.data_pixel = (int *)mlx_get_data_addr(win.img, &win.bpp, &win.size_line, &win.endian);
    ft_rays(&pc, &input, &win);
    mlx_put_image_to_window(win.mlx, win.window, win.img, 0, 0);
    mlx_hook(win.window, KeyPress, KeyPressMask, ft_press_key, &win);
	mlx_hook(win.window, 17, 0, ft_clean, &win);
    mlx_loop(win.mlx);
    
}

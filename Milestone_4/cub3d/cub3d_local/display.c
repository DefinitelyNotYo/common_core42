/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/25 17:29:20 by cciapett          #+#    #+#             */
/*   Updated: 2025/07/31 15:49:55 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void    ft_display(t_pc *pc, t_win *win, int x) //x e' la colonna dello schermo
{
    int i;
    int c;

    i = 0;
    (void)x;
    c = WIDTH*HEIGHT/2;

    if (pc->lineHeight < 0)
    {
        printf("lineHeight/2: %d\n", (int)pc->lineHeight/2);
        return ;
    }

    while (i < (int)pc->lineHeight/2)
    {
        win->data_pixel[c - (WIDTH * i) + x] = create_trgb(0, 255, 0, 0);
        i++;
    }
    i = 0;
    while (i < (int)pc->lineHeight/2)
    {
        win->data_pixel[c + (WIDTH * i) + x] = create_trgb(0, 255, 0, 0);
        i++;
    }
    i = 0;
    while (i < (int)HEIGHT/2 - (int)pc->lineHeight/2)
    {
        win->data_pixel[i *WIDTH + x] = create_trgb(100, 80, 80, 230);
        i++;
    }
    i =  (int)HEIGHT/2 + (int)pc->lineHeight/2;
    while (i < HEIGHT)
    {
        win->data_pixel[i *WIDTH + x] = create_trgb(100, 80, 230, 80);
        i++;
    }
}

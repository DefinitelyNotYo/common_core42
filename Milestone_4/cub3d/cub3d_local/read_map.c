/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:41:32 by cciapett          #+#    #+#             */
/*   Updated: 2025/07/31 17:43:41 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char ft_search_letter(char c, char *str)
{
    int i;

    i = -1;
    while (str[++i] != '\0')
    {
        if (str[i] == c)
            return (str[i]);
    }
    return (0);
}

static void ft_det_dir(t_pc *pc, char c)
{
    if (c == 'N')
    {
        pc->dirX = 0;
        pc->dirY = 1;
    }
    if (c == 'S')
    {
        pc->dirX = 0;
        pc->dirY = -1;
    }
    if (c == 'E')
    {
        pc->dirX = 1;
        pc->dirY = 0;
    }
    if (c == 'W')
    {
        pc->dirX = -1;
        pc->dirY = 0;
    }
}


void    ft_read_map(t_input *input, t_pc *pc)
{
    int     i;
    int     j;
    char    *str;

    str = "NSEW";
    i = -1;
    while(input->map[++i] != NULL)
    {
        j = -1;
        while (input->map[i][++j] != '\0')
        {
            if (ft_search_letter(input->map[i][j], str) != 0)
            {
                char c = ft_search_letter(input->map[i][j], str); //riga da togliere
                pc->posX = j + 0.5;
                pc->posY = i + 0.5;
                pc->mapX = (int)pc->posX;
                pc->mapY = (int)pc->posY;
                ft_det_dir(pc, ft_search_letter(input->map[i][j], str));
                printf("\nTrovata %c in posizione %f %f\ncon direzione %f %f\n", c, pc->posX, pc->posY, pc->dirX, pc->dirY);
            }
        }
    }
    pc->planeX = pc->dirY * FOV_SCALE;
    pc->planeY = -pc->dirX * FOV_SCALE;
    printf("planeX %f\nplaneY %f\n", pc->planeX, pc->planeY);
}

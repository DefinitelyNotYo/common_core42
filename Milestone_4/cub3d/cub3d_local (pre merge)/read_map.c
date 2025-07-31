/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 14:41:32 by cciapett          #+#    #+#             */
/*   Updated: 2025/07/22 17:09:45 by cciapett         ###   ########.fr       */
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
    pc->angle_fov = 0.66;
}


void    ft_read_map(t_input *input)
{
    int     i;
    int     j;
    char    *str;
    t_pc    pc;

    str = "NSEW";
    i = -1;
    while(++i < input->file_rows)
    {
        j = -1;
        while (input->file[i][++j] != '\0')
        {
            if (ft_search_letter(input->file[i][j], str) != 0)
            {
                char c = ft_search_letter(input->file[i][j], str); //riga da togliere
                pc.posX = i;
                pc.posY = j;
                ft_det_dir(&pc, ft_search_letter(input->file[i][j], str));
                printf("\nTrovata %c in posizione %f %f\ncon direzione %f %f\n", c, pc.posX, pc.posY, pc.dirX, pc.dirY);
            }
        }
    }
    pc.planeX = pc.dirY * pc.angle_fov;
    pc.planeY = -pc.dirX * pc.angle_fov;
    printf("planeX %f\nplaneY %f\n", pc.planeX, pc.planeY);
}

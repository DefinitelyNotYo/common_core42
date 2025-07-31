/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 16:43:49 by yoherfan          #+#    #+#             */
/*   Updated: 2025/07/31 17:01:53 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	check_north(t_input *in, int *elements, int *indxs, char *dir)
{
	int	j;

	j = indxs[1] + 3;
    if (dir[0] == 'N')
		{
			if (elements[0] == 0)
			{
				elements[0] = 1;
				while (in->file[indxs[0]][j] == ' ')
					j++;
				in->t[0].texture_path = ft_strdup(&in->file[indxs[0]][j]);
				in->t[0].direction = ft_strdup("NO");
			}
			else
				elements[0] = -1;		
		}
}

void	check_south(t_input *in, int *elements, int *indxs, char *dir)
{
	int	j;

	j = indxs[1] + 3;
	if (dir[0] == 'S')
	{
		if (elements[1] == 0)
		{
			elements[1] = 1;
			while (in->file[indxs[0]][j] == ' ')
					j++;
			in->t[1].texture_path = ft_strdup(&in->file[indxs[0]][j]);
			in->t[1].direction = ft_strdup("SO");
		}
		else
			elements[1] = -1;			
	}
}

void	check_west(t_input *in, int *elements, int *indxs, char *dir)
{
	int	j;

	j = indxs[1] + 3;
	if (dir[0] == 'W')
	{
		if (elements[2] == 0)
		{
			elements[2] = 1;
			while (in->file[indxs[0]][j] == ' ')
				j++;
			in->t[2].texture_path = ft_strdup(&in->file[indxs[0]][j]);
			in->t[2].direction = ft_strdup("WE");
		}
		else
			elements[2] = -1;			
	}
}

void	check_east(t_input *in, int *elements, int *indxs, char *dir)
{
	int	j;

	j = indxs[1] + 3;
	if (dir[0] == 'E')
	{
		if (elements[3] == 0)
		{
			elements[3] = 1;
			while (in->file[indxs[0]][j] == ' ')
				j++;
			in->t[3].texture_path = ft_strdup(&in->file[indxs[0]][j]);
			in->t[3].direction = ft_strdup("EA");
		}
		else
			elements[3] = -1;			
	}
}

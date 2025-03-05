/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_floodfill.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 16:16:39 by yoherfan          #+#    #+#             */
/*   Updated: 2025/02/25 13:49:32 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_floodfill(void *params)
{
	t_param	*dummy;
	int		coord[2];
	int		check;

	ft_set_character(params);
	dummy = (t_param *)params;
	coord[0] = dummy->pc.p_row;
	coord[1] = dummy->pc.p_col;
	ft_floodfill_exe(dummy, coord[0], coord[1]);
	check = ft_floodcheck(dummy);
	if (check == 1)
		return (1);
	return (0);
}

void	ft_floodfill_exe(t_param *dummy, int r, int c)
{
	dummy->map[r][c] = 'x';
	if (dummy->map[r + 1][c] != '1' && dummy->map[r + 1][c] != 'x')
		ft_floodfill_exe(dummy, r + 1, c);
	if (dummy->map[r - 1][c] != '1' && dummy->map[r - 1][c] != 'x')
		ft_floodfill_exe(dummy, r - 1, c);
	if (dummy->map[r][c + 1] != '1' && dummy->map[r][c + 1] != 'x')
		ft_floodfill_exe(dummy, r, c + 1);
	if (dummy->map[r][c - 1] != '1' && dummy->map[r][c - 1] != 'x')
		ft_floodfill_exe(dummy, r, c - 1);
}

int	ft_floodcheck(t_param *dummy)
{
	int	i;
	int	j;

	i = 0;
	while (i < dummy->map_rows)
	{
		j = 0;
		while (dummy->map[i][j] != '\0' && dummy->map[i][j] != '\n')
		{
			if (dummy->map[i][j] != '1' && dummy->map[i][j] != 'x')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

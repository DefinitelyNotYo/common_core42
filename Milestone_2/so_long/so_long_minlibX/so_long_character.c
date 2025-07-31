/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_character.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:28:38 by yoherfan          #+#    #+#             */
/*   Updated: 2025/03/04 14:08:19 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_coins(void *params)
{
	t_param	*dummy;
	int		i;
	int		j;

	dummy = (t_param *)params;
	i = -1;
	j = -1;
	dummy->pc.total_coins = 0;
	dummy->pc.coins = 0;
	dummy->moves = 0;
	dummy->clock = 0;
	dummy->pc.pov = 'f';
	while (++i < dummy->map_rows)
	{
		j = -1;
		while (++j < ft_strlen(dummy->map[i]))
		{
			if (dummy->map[i][j] == 'C')
			{
				dummy->pc.total_coins++;
			}
		}
	}
}

void	ft_set_position(void *params)
{
	t_param	*dummy;
	int		i;
	int		j;

	dummy = (t_param *)params;
	i = -1;
	j = -1;
	dummy->pc.on_exit = 0;
	while (++i < dummy->map_rows)
	{
		j = -1;
		while (++j < ft_strlen(dummy->map[i]))
		{
			if (dummy->map[i][j] == 'P')
			{
				dummy->pc.p_row = i;
				dummy->pc.p_col = j;
			}
		}
	}
}

void	ft_set_character(void *params)
{
	ft_set_coins(params);
	ft_set_position(params);
}

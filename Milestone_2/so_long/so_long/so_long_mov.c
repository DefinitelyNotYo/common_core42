/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mov.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 17:13:56 by yoherfan          #+#    #+#             */
/*   Updated: 2025/03/04 14:09:36 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_move_manager(int key, void *params)
{
	t_param	*dummy;

	dummy = (t_param *)params;
	if (XK_Up == key)
		ft_move_up(dummy, params);
	else if (XK_Down == key)
		ft_move_down(dummy, params);
	else if (XK_Left == key)
		ft_move_left(dummy, params);
	else if (XK_Right == key)
		ft_move_right(dummy, params);
	ft_draw_map(params);
	return (0);
}

void	ft_move_up(t_param *dummy, void *params)
{
	int	coord[2];

	dummy->pc.pov = 'b';
	coord[0] = dummy->pc.p_row;
	coord[1] = dummy->pc.p_col;
	if (dummy->map[coord[0] - 1][coord[1]] != '1')
	{
		if (dummy->map[coord[0] - 1][coord[1]] == 'E' && \
			dummy->pc.coins == dummy->pc.total_coins)
			ft_clean_board2(params);
		if (dummy->map[coord[0] - 1][coord[1]] == 'C')
			dummy->pc.coins++;
		if (dummy->pc.on_exit == 1)
		{
			dummy->map[coord[0]][coord[1]] = 'E';
			dummy->pc.on_exit = 0;
		}
		else
			dummy->map[coord[0]][coord[1]] = '0';
		if (dummy->map[coord[0] - 1][coord[1]] == 'E')
			dummy->pc.on_exit = 1;
		dummy->map[coord[0] - 1][coord[1]] = 'P';
		dummy->pc.p_row = dummy->pc.p_row - 1;
		ft_put_move(params, 1);
	}
}

void	ft_move_down(t_param *dummy, void *params)
{
	int	coord[2];

	dummy->pc.pov = 'f';
	coord[0] = dummy->pc.p_row;
	coord[1] = dummy->pc.p_col;
	if (dummy->map[coord[0] + 1][coord[1]] != '1')
	{
		if (dummy->map[coord[0] + 1][coord[1]] == 'E' && \
			dummy->pc.coins == dummy->pc.total_coins)
			ft_clean_board2(params);
		if (dummy->map[coord[0] + 1][coord[1]] == 'C')
			dummy->pc.coins++;
		if (dummy->pc.on_exit == 1)
		{
			dummy->map[coord[0]][coord[1]] = 'E';
			dummy->pc.on_exit = 0;
		}
		else
			dummy->map[coord[0]][coord[1]] = '0';
		if (dummy->map[coord[0] + 1][coord[1]] == 'E')
			dummy->pc.on_exit = 1;
		dummy->map[coord[0] + 1][coord[1]] = 'P';
		dummy->pc.p_row = dummy->pc.p_row + 1;
		ft_put_move(params, 1);
	}
}

void	ft_move_left(t_param *dummy, void *params)
{
	int	coord[2];

	dummy->pc.pov = 'l';
	coord[0] = dummy->pc.p_row;
	coord[1] = dummy->pc.p_col;
	if (dummy->map[coord[0]][coord[1] - 1] != '1')
	{
		if (dummy->map[coord[0]][coord[1] - 1] == 'E' && \
			dummy->pc.coins == dummy->pc.total_coins)
			ft_clean_board2(params);
		if (dummy->map[coord[0]][coord[1] - 1] == 'C')
			dummy->pc.coins++;
		if (dummy->pc.on_exit == 1)
		{
			dummy->map[coord[0]][coord[1]] = 'E';
			dummy->pc.on_exit = 0;
		}
		else
			dummy->map[coord[0]][coord[1]] = '0';
		if (dummy->map[coord[0]][coord[1] - 1] == 'E')
			dummy->pc.on_exit = 1;
		dummy->map[coord[0]][coord[1] - 1] = 'P';
		dummy->pc.p_col = dummy->pc.p_col - 1;
		ft_put_move(params, 1);
	}
}

void	ft_move_right(t_param *dummy, void *params)
{
	int	coord[2];

	dummy->pc.pov = 'r';
	coord[0] = dummy->pc.p_row;
	coord[1] = dummy->pc.p_col;
	if (dummy->map[coord[0]][coord[1] + 1] != '1')
	{
		if (dummy->map[coord[0]][coord[1] + 1] == 'E' && \
			dummy->pc.coins == dummy->pc.total_coins)
			ft_clean_board2(params);
		if (dummy->map[coord[0]][coord[1] + 1] == 'C')
			dummy->pc.coins++;
		if (dummy->pc.on_exit == 1)
		{
			dummy->map[coord[0]][coord[1]] = 'E';
			dummy->pc.on_exit = 0;
		}
		else
			dummy->map[coord[0]][coord[1]] = '0';
		if (dummy->map[coord[0]][coord[1] + 1] == 'E')
			dummy->pc.on_exit = 1;
		dummy->map[coord[0]][coord[1] + 1] = 'P';
		dummy->pc.p_col = dummy->pc.p_col + 1;
		ft_put_move(params, 1);
	}
}

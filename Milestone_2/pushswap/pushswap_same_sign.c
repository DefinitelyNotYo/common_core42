/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_same_sign.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 14:44:22 by yoherfan          #+#    #+#             */
/*   Updated: 2025/02/11 16:37:14 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_exe_pos_case_1(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	while (cost_b > 0)
	{
		combo_rotate(a, b);
		cost_b--;
		cost_a--;
		update_indexs(a, b);
	}
	while (cost_a > 0)
	{
		rotate(a, 97);
		cost_a--;
		update_indexs(a, b);
	}
}

void	sort_exe_pos_case_2(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	while (cost_a > 0)
	{
		combo_rotate(a, b);
		cost_a--;
		cost_b--;
		update_indexs(a, b);
	}
	while (cost_b > 0)
	{
		rotate(b, 98);
		cost_b--;
		update_indexs(a, b);
	}
}

void	sort_exe_neg_case_1(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	while (cost_b < 0)
	{
		combo_reverse_rotate(a, b);
		cost_b++;
		cost_a++;
		update_indexs(a, b);
	}
	while (cost_a < 0)
	{
		reverse_rotate(a, 97);
		cost_a++;
		update_indexs(a, b);
	}
}

void	sort_exe_neg_case_2(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	while (cost_a < 0)
	{
		combo_reverse_rotate(a, b);
		cost_a++;
		cost_b++;
		update_indexs(a, b);
	}
	while (cost_b < 0)
	{
		reverse_rotate(b, 98);
		cost_b++;
		update_indexs(a, b);
	}
}

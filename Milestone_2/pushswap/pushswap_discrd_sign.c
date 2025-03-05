/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_discrd_sign.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:58:54 by yoherfan          #+#    #+#             */
/*   Updated: 2025/02/11 16:49:15 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_exe_dis_case_1(t_stack **a, t_stack **b, int *cost_a)
{
	if (*cost_a > 0)
	{
		rotate(a, 97);
		*cost_a = *cost_a - 1;
		update_indexs(a, b);
	}
	else
	{
		reverse_rotate(a, 97);
		*cost_a = *cost_a + 1;
		update_indexs(a, b);
	}
}

void	sort_exe_dis_case_2(t_stack **a, t_stack **b, int *cost_b)
{
	if (*cost_b > 0)
	{
		rotate(b, 98);
		*cost_b = *cost_b - 1;
		update_indexs(a, b);
	}
	else
	{
		reverse_rotate(b, 98);
		*cost_b = *cost_b + 1;
		update_indexs(a, b);
	}
}

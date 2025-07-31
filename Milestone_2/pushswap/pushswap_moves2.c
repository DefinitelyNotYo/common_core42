/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_moves2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 17:46:27 by yoherfan          #+#    #+#             */
/*   Updated: 2025/02/11 16:42:19 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	combo_reverse_rotate(t_stack **a, t_stack **b)
{
	reverse_rotate(a, 0);
	reverse_rotate(b, 0);
	write(1, "rrr\n", 4);
}

void	combo_rotate(t_stack **a, t_stack **b)
{
	rotate(a, 0);
	rotate(b, 0);
	write(1, "rr\n", 3);
}

// void	combo_swap(t_stack **a, t_stack **b)
// {
//     swap(a);
//     swap(b);
// }
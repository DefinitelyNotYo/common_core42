/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_updater.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:53:49 by yoherfan          #+#    #+#             */
/*   Updated: 2025/02/11 16:30:04 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	update_costs(t_stack **a, t_stack **b, int **a_costs, int **b_costs)
{
	int	lenght_a;
	int	lenght_b;
	int	i;

	lenght_a = ft_stacksize(*a);
	lenght_b = ft_stacksize(*b);
	*a_costs = ft_calloc(lenght_a, 4);
	*b_costs = ft_calloc(lenght_b, 4);
	i = -1;
	while (++i < lenght_a)
	{
		if (i <= lenght_a / 2)
			a_costs[0][i] = i;
		if (i > lenght_a / 2)
			a_costs[0][i] = -1 * (lenght_a - i);
	}
	i = -1;
	while (++i < lenght_b)
	{
		if (i <= lenght_b / 2)
			b_costs[0][i] = i;
		if (i > lenght_b / 2)
			b_costs[0][i] = -1 * (lenght_b - i);
	}
}

void	update_indexs(t_stack **a, t_stack **b)
{
	int		i;
	t_stack	*node_a;
	t_stack	*node_b;

	node_a = *a;
	node_b = *b;
	i = 0;
	while (node_a)
	{
		node_a -> index = i;
		i++;
		node_a = node_a -> next;
	}
	i = 0;
	while (node_b)
	{
		node_b -> index = i;
		i++;
		node_b = node_b -> next;
	}
}

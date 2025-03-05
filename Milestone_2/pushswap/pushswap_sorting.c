/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_sorting.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 14:05:58 by yoherfan          #+#    #+#             */
/*   Updated: 2025/02/11 16:36:11 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_sorting(t_stack **a, t_stack **b)
{
	int	*a_costs;
	int	*b_costs;
	int	*indexs;
	int	i;

	i = 0;
	update_costs(a, b, &a_costs, &b_costs);
	update_indexs(a, b);
	indexs = find_indexs(a, b, a_costs, b_costs);
	sort_exe(a, b, a_costs[indexs[0]], b_costs[indexs[1]]);
	return (free(a_costs), free(b_costs), free(indexs));
}

int	*find_indexs(t_stack **a, t_stack **b, int *a_c, int *b_c)
{
	int			cheaper_cost;
	t_stack		*node_b;
	t_stack		*node;
	int			index_a;
	int			*indexs;

	cheaper_cost = 2147483647;
	node_b = *b;
	indexs = ft_calloc(2, 4);
	node = NULL;
	while (node_b != NULL)
	{
		index_a = find_min_from_max(a, node_b);
		if (index_a == 2147483647)
			index_a = find_min(a);
		if (cheaper_cost > pair_cost(index_a, node_b -> index, a_c, b_c))
		{
			cheaper_cost = pair_cost(index_a, node_b -> index, a_c, b_c);
			indexs[0] = index_a;
			indexs[1] = node_b -> index;
		}
		node_b = node_b -> next;
	}
	return (indexs);
}

int	pair_cost(int index_a, int index_b, int *a_costs, int *b_costs)
{
	if (a_costs[index_a] >= 0 && b_costs[index_b] >= 0)
	{
		if (a_costs[index_a] > b_costs[index_b])
			return (a_costs[index_a]);
		else
			return (b_costs[index_b]);
	}
	else if (a_costs[index_a] < 0 && b_costs[index_b] < 0)
	{
		if (a_costs[index_a] < b_costs[index_b])
			return (ft_abs(a_costs[index_a]));
		else
			return (ft_abs(b_costs[index_b]));
	}
	else
		return (ft_abs(a_costs[index_a]) + ft_abs(b_costs[index_b]));
}

void	sort_exe(t_stack **a, t_stack **b, int cost_a, int cost_b)
{
	if (cost_a > 0 && cost_b > 0)
	{
		if (cost_a > cost_b)
			sort_exe_pos_case_1 (a, b, cost_a, cost_b);
		else
			sort_exe_pos_case_2 (a, b, cost_a, cost_b);
	}
	else if (cost_a < 0 && cost_b < 0)
	{
		if (cost_a < cost_b)
			sort_exe_neg_case_1 (a, b, cost_a, cost_b);
		else
			sort_exe_neg_case_2 (a, b, cost_a, cost_b);
	}
	else
	{
		while (cost_a != 0)
			sort_exe_dis_case_1 (a, b, &cost_a);
		while (cost_b != 0)
			sort_exe_dis_case_2 (a, b, &cost_b);
	}
	push_from_to(b, a, 97);
	update_indexs(a, b);
}

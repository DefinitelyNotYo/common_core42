/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 15:52:33 by yoherfan          #+#    #+#             */
/*   Updated: 2025/02/11 16:28:53 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	find_min_from_max(t_stack **a, t_stack *node_b)
{
	int		index;
	int		content;
	t_stack	*node;

	node = *a;
	index = 2147483647;
	content = 2147483647;
	while (node != NULL && node_b != NULL)
	{
		if (node -> content > node_b -> content && node -> content < content)
		{
			content = node -> content;
			index = node -> index;
		}
		node = node -> next;
	}
	if (index == 2147483647)
		return (2147483647);
	return (index);
}

int	find_min(t_stack **a)
{
	int		index;
	int		content;
	t_stack	*node;

	node = *a;
	index = 2147483647;
	content = 2147483647;
	while (node != NULL)
	{
		if (node -> content < content)
		{
			content = node -> content;
			index = node -> index;
		}
		node = node -> next;
	}
	if (index == 2147483647)
		return (2147483647);
	return (index);
}

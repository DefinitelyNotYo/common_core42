/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_foreplay.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:54:50 by yoherfan          #+#    #+#             */
/*   Updated: 2025/02/11 16:48:48 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	first_sort(t_stack **s)
{
	t_stack	*node;
	int		lenght;

	node = *s;
	lenght = ft_stacksize(node);
	if (lenght == 2)
		if (node -> content > node -> next -> content)
			swap(s, 97);
	if (lenght > 2)
		sort_three(s);
}

void	sort_three(t_stack **s)
{
	long long	node_0;
	long long	node_1;
	long long	node_2;

	node_0 = (*s)-> content;
	node_1 = (*s)-> next -> content;
	node_2 = (*s)-> next -> next -> content;
	if (node_0 < node_1 && node_0 < node_2 && node_1 > node_2)
	{
		rotate(s, 97);
		swap(s, 97);
		reverse_rotate(s, 97);
	}
	else if (node_0 > node_1 && node_0 < node_2 && node_1 < node_2)
		swap(s, 97);
	else if (node_0 < node_1 && node_0 > node_2 && node_1 > node_2)
		reverse_rotate(s, 97);
	else if (node_0 > node_1 && node_1 < node_2 && node_0 > node_2)
		rotate(s, 97);
	else if (node_0 > node_1 && node_1 > node_2 && node_0 > node_2)
	{
		swap(s, 97);
		reverse_rotate(s, 97);
	}
}

int	check_stack(t_stack **s)
{
	t_stack	*node;
	int		check;

	node = *s;
	check = 1;
	while (node -> next != NULL)
	{
		if (node -> content > node -> next -> content)
			check = 0;
		node = node -> next;
	}
	return (check);
}

void	push_foreplay(t_stack **a, t_stack **b)
{
	int	stack_lenght;

	stack_lenght = ft_stacksize(*a);
	while (stack_lenght > 3)
	{
		push_from_to(a, b, 98);
		stack_lenght--;
	}
}

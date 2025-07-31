/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 16:02:38 by yoherfan          #+#    #+#             */
/*   Updated: 2025/02/11 16:46:24 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_from_to(t_stack **a, t_stack **b, int toggle)
{
	t_stack	*dummy;
	t_stack	*dummy2;

	if (ft_stacksize(*a) == 0)
		return ;
	dummy = *a;
	dummy2 = (*a)-> next;
	ft_add_node(b, dummy);
	*a = dummy2;
	if (toggle == 97)
		write(1, "pa\n", 3);
	if (toggle == 98)
		write(1, "pb\n", 3);
}

void	swap(t_stack **s, int toggle)
{
	t_stack	*dummy;
	t_stack	*dummy2;
	t_stack	*dummy3;
	int		stack_lenght;

	stack_lenght = ft_stacksize(*s);
	if (stack_lenght < 2)
		return ;
	if (stack_lenght > 2)
		dummy3 = ((*s)-> next)-> next;
	dummy = *s;
	dummy2 = (*s)-> next;
	*s = dummy2;
	(*s)-> next = dummy;
	if (stack_lenght > 2)
		(*s)-> next -> next = dummy3;
	else
		(*s)-> next -> next = NULL;
	if (toggle == 97)
		write(1, "sa\n", 3);
	if (toggle == 98)
		write(1, "sb\n", 3);
}

t_stack	*ft_lastnode(t_stack **s, int toggle)
{
	t_stack	*node;

	node = *s;
	if (toggle == 0)
	{
		if (!node)
			return (NULL);
		while (node -> next != NULL)
			node = node -> next;
		return (node);
	}
	else
	{
		if (!node || !(node -> next))
			return (NULL);
		while (node -> next -> next != NULL)
			node = node -> next;
		return (node);
	}
}

void	rotate(t_stack **s, int toggle)
{
	t_stack	*dummy;
	t_stack	*dummy2;
	t_stack	*dummy3;
	int		stack_lenght;

	stack_lenght = ft_stacksize(*s);
	if (stack_lenght < 2)
		return ;
	if (stack_lenght > 2)
	{
		dummy3 = (*s)-> next;
		dummy = *s;
		dummy2 = ft_lastnode(s, 0);
		*s = dummy3;
		dummy2 -> next = dummy;
		dummy -> next = NULL;
	}
	else
	{
		swap(s, 0);
	}
	if (toggle == 97)
		write(1, "ra\n", 3);
	if (toggle == 98)
		write(1, "rb\n", 3);
}

void	reverse_rotate(t_stack **s, int toggle)
{
	t_stack	*dummy;
	t_stack	*dummy2;
	t_stack	*dummy3;
	int		stack_lenght;

	stack_lenght = ft_stacksize(*s);
	if (stack_lenght < 2)
		return ;
	if (stack_lenght > 2)
	{
		dummy = *s;
		dummy2 = ft_lastnode(s, 0);
		dummy3 = ft_lastnode(s, 1);
		dummy3 -> next = NULL;
		dummy2 -> next = dummy;
		*s = dummy2;
	}
	else
		swap(s, 0);
	if (toggle == 97)
		write(1, "rra\n", 4);
	if (toggle == 98)
		write(1, "rrb\n", 4);
}

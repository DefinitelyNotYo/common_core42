/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:47:29 by yoherfan          #+#    #+#             */
/*   Updated: 2025/02/11 18:18:15 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	*ft_newnode(long long content)
{
	t_stack	*node;

	node = calloc(1, sizeof(t_stack));
	if (!node)
		return (NULL);
	node -> content = content;
	node -> next = NULL;
	return (node);
}

int	ft_stacksize(t_stack *stk)
{
	if (stk == NULL)
		return (0);
	else
		return (1 + ft_stacksize(stk -> next));
}

void	ft_add_node(t_stack **stk, t_stack *new)
{
	if (!new)
		return ;
	new -> next = *stk;
	*stk = new;
}

// void	ft_show_stack(t_stack **stk)
// {
// 	if (ft_stacksize(*stk) == 0)
// 		return ;
// 	ft_putnbr((*stk) -> content);
// 	write(1, "\n", 1);
// 	ft_show_stack(&((*stk) -> next));		
// }

void	ft_clean_stack(t_stack **stk)
{
	t_stack	*dummy;

	while (*stk != NULL)
	{
		dummy = (*stk)-> next;
		free (*stk);
		*stk = dummy;
	}
	*stk = NULL;
}

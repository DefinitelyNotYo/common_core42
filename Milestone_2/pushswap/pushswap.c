/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:42:57 by yoherfan          #+#    #+#             */
/*   Updated: 2025/02/25 15:48:35 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_pushswap(t_stack **a, t_stack **b)
{
	if (ft_sorted_stack(a) == 1)
		return ;
	push_foreplay(a, b);
	first_sort(a);
	while (ft_stacksize(*b) != 0)
	{
		update_indexs(a, b);
		ft_sorting(a, b);
	}
	update_indexs(a, b);
	fix_sorting(a, find_min(a));
	update_indexs(a, b);
}

int	ft_sorted_stack(t_stack **s)
{
	t_stack	*node;

	node = *s;
	while (node -> next != NULL)
	{
		if (node -> content > node -> next -> content)
			return (0);
		node = node -> next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack		**a;
	t_stack		**b;
	int			i;
	int			check;

	a = ft_calloc(1, sizeof(t_stack *));
	b = ft_calloc(1, sizeof(t_stack *));
	i = argc;
	if (argc <= 1)
		return (free(a), free(b), 0);
	while (--i > 0)
		if (parsing(a, argv[i]) == 0)
			return (write(2, "Error\n", 6), ft_clean_stack(a), \
				ft_clean_stack(b), free(a), free(b), 0);
	check = check_duplicates(a);
	if (check == 0)
		return (write(1, "Error\n", 6), ft_clean_stack(a), \
			ft_clean_stack(b), free(a), free(b), 0);
	ft_pushswap(a, b);
	return (ft_clean_stack(a), ft_clean_stack(b), free(a), free(b), 0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:31:17 by yoherfan          #+#    #+#             */
/*   Updated: 2025/02/25 15:48:12 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_number(char *str)
{
	int	i;
	int	sign;	

	i = 0;
	sign = 1;
	while (str[i] != '\0')
	{
		if (str[i] < 48 || str[i] > 57)
		{
			if (i == 0 && (str[0] == '-' || str[0] == '+'))
				;
			else
				return (0);
		}
		i++;
	}
	return (1);
}

int	check_overflows(long long n)
{
	if (n >= -2147483648 && n <= 2147483647)
		return (1);
	else
		return (0);
}

int	check_duplicates(t_stack **s)
{
	t_stack	*node1;
	t_stack	*node2;
	int		check;

	check = 1;
	node1 = *s;
	node2 = *s;
	if (!*s)
		return (0);
	while (node1 -> next != NULL)
	{
		node2 = *s;
		check = 1;
		while (node2 != NULL)
		{
			if (node2 -> content == node1 -> content)
				check--;
			node2 = node2 -> next;
		}
		if (check < 0)
			return (0);
		node1 = node1 -> next;
	}
	return (1);
}

int	parsing(t_stack **s, char *str)
{
	long long	num;

	if (is_number(str) == 1)
	{
		num = ft_atoi(str);
		if (check_overflows(num) == 1)
			ft_add_node(s, ft_newnode(num));
		else
			return (0);
	}
	else
		if (split_v2(str, s) != 1)
			return (0);
	return (1);
}

void	fix_sorting(t_stack **s, int index)
{
	int	stack_lenght;

	stack_lenght = ft_stacksize(*s);
	if (index >= stack_lenght / 2)
	{
		while (index < stack_lenght)
		{
			reverse_rotate(s, 97);
			index++;
		}
	}
	else
	{
		while (index > 0)
		{
			rotate(s, 97);
			index--;
		}
	}
}

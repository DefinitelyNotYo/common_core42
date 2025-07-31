/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:35:09 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/06 15:55:18 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 1;
	if (!lst)
		return (0);
	while (lst -> next != NULL)
	{
		i++;
		lst = lst -> next;
	}
	return (i);
}

// int main()
// {
//     t_list *dummy1 = ft_lstnew("dummy_1");
//     t_list *dummy2 = ft_lstnew("dummy_2");
//     t_list *dummy3 = ft_lstnew("dummy_3");

// 	dummy1 -> next = dummy2;
// 	dummy2 -> next = dummy3;
//     printf("%d", ft_lstsize(dummy1));
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:58:28 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/06 17:18:31 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}

// int main()
// {
//     t_list *dummy1 = ft_lstnew("dummy_1");
//     t_list *dummy2 = ft_lstnew("dummy_2");
//     t_list *dummy3 = ft_lstnew("dummy_3");

// 	dummy1 -> next = dummy2;
// 	dummy2 -> next = dummy3;
//     printf("%s", (char *)ft_lstlast(dummy1) -> content);
// }
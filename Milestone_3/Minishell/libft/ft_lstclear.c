/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:35:03 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/10 15:40:41 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void ft_lstdel(void *lst)
// {
// 	if (!lst)
// 		return ;
// }

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*dummy;

	if (!lst || !del || !*lst)
		return ;
	while (*lst)
	{
		dummy = (*lst)-> next;
		ft_lstdelone(*lst, del);
		free(*lst);
		*lst = dummy;
	}
	*lst = NULL;
}

// int main()
// {
//     t_list *dummy1 = ft_lstnew(ft_strdup("dummy_1"));
//     t_list *dummy2 = ft_lstnew(ft_strdup("dummy_2"));
//     t_list *dummy3 = ft_lstnew(ft_strdup("dummy_3"));

// 	dummy1 -> next = dummy2;
// 	dummy2 -> next = dummy3;
// 	printf("%s\n", (char *)ft_lstlast(dummy1) -> content);
// 	ft_lstclear(&dummy1, ft_lstdel);
// 	printf("%s", (char *)ft_lstlast(dummy1) -> content);
// }
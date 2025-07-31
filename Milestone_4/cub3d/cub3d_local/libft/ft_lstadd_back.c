/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:10:41 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/06 18:28:08 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	while ((*lst)-> next != NULL)
		*lst = (*lst)-> next;
	(*lst)-> next = new;
}

// int main()
// {
//     t_list *dummy_1 = ft_lstnew("dummy_1");
//     t_list *dummy_2 = ft_lstnew("dummy_2");
//     t_list *dummy_3 = ft_lstnew("dummy_3");
// 	t_list **dummy_list = malloc(sizeof(t_list *));

// 	ft_lstadd_front(dummy_list, dummy_1);
// 	ft_lstadd_back(dummy_list, dummy_2);
// 	ft_lstadd_back(dummy_list, dummy_3);
// 	printf("%s", (char *)ft_lstlast(*dummy_list) -> content);
// }
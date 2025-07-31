/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 15:20:12 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/06 17:05:41 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new)
		return ;
	new -> next = *lst;
	*lst = new;
}

// int main()
// {
//     t_list *dummy_1 = ft_lstnew("dummy_1");
//     t_list *dummy_2 = ft_lstnew("dummy_2");
// 	t_list **dummy_list = malloc(sizeof(t_list *));

// 	ft_lstadd_front(dummy_list, dummy_1);
// 	ft_lstadd_front(dummy_list, dummy_2);
//     printf("%s", (char *)(*dummy_list) -> content);
// }
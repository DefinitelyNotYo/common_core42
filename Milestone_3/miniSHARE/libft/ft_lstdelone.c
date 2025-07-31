/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 14:48:36 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/10 14:43:57 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst -> content);
	free(lst -> content);
}

// void ft_lstdel(t_list *lst)
// {
// 	if (!lst)
// 		return ;
// 	free(lst -> content);
// }
// int main()
// {
//     t_list *dummy = ft_lstnew("dummy_string");
//     printf("%s\n", (char *)dummy -> content);
// 	ft_lstdelone(dummy, ft_del);
//     printf("%s", (char *)dummy -> content);
// }
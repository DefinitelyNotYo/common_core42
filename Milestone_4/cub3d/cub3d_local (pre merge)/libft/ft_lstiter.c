/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 17:27:24 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/10 14:44:15 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void ft_setcontent(void *content)
// {
// 	int	i = 0;
// 	int len = ft_strlen((char *)content);
// 	while(i < len)
// 	{
// 		((char *)content)[i] = 'x';  
// 		i++;	
// 	}                    
//     printf("%s\n", "sono entrato nel ciclo");
// }
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f((lst -> content));
		lst = lst -> next;
	}
}

// int main()
// {
// 	char str[10] = "ciao";
//     t_list *dummy1 = ft_lstnew(str);
//     t_list *dummy2 = ft_lstnew(str);
//     t_list *dummy3 = ft_lstnew(str);
// 	dummy1 -> next = dummy2;
// 	dummy2 -> next = dummy3;
//     ft_lstiter(dummy1, ft_setcontent);
//     printf("%s\n", (char *)dummy1 -> content);
//     printf("%s\n", (char *)dummy2 -> content);
//     printf("%s\n", (char *)dummy3 -> content);
// }
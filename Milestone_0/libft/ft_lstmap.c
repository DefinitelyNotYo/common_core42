/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:45:43 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/10 16:35:35 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_setcontent(void *content)
{
	t_list	*node;
	
	node -> content = ((char *)content - 1);            
    return (node);
}

void ft_lstdel(void *lst)
{
	if (!lst)
		return ;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst -> next != NULL)
    {
        printf("%s\n", (char *)lst -> content);
        lst = lst -> next;
    }
	return (lst);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*first_node;

	if (!lst || !f || !del)
		return (NULL);
	first_node = NULL;
	while (lst)
	{
		if(!(node = ft_lstnew((*f)(lst -> content))))
		{
			while (first_node)
			{
				node = first_node -> next;
				(*del)(first_node -> content);
				free(first_node);
				first_node = node;
			}
			lst = NULL;
			return (NULL);

		}
		ft_lstadd_back(&first_node, node);
		lst = lst -> next;
	}
	return (first_node);
}

int main()
{
	char str[10] = "ciao";
    t_list *dummy1 = ft_lstnew(str);
    t_list *dummy2 = ft_lstnew(str);
    t_list *dummy3 = ft_lstnew(str);

	dummy1 -> next = dummy2;
	dummy2 -> next = dummy3;
    t_list *new = ft_lstmap(dummy1, *ft_setcontent, ft_lstdel);
	printf("%s", (char *)new -> content);
//   ft_lstlast(new);
}

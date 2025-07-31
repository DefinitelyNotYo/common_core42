/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:08:12 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/04 16:40:26 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123))
		return (1024);
	else
		return (0);
}
/*
int main()
{
    int i = 123;
    int result = isalpha(i);
    int ft_result = ft_isalpha(i);
    printf("%d", result);
    printf("\n%d", ft_result);
}*/

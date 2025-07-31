/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:11:39 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/04 16:40:15 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c > 31 && c < 127)
		return (16384);
	else
		return (0);
}
/*
int main()
{
    int i = 123;
    int result = isprint(i);
    int ft_result = ft_isprint(i);
    printf("%d", result);
    printf("\n%d", ft_result);
}*/
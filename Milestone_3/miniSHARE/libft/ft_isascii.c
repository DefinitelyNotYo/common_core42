/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:03:08 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/04 16:40:23 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	if (c > -1 && c < 128)
		return (1);
	else
		return (0);
}
/*
int main()
{
    int i = -1;
    int result = isascii(i);
    int ft_result = ft_isascii(i);
    printf("%d", result);
    printf("\n%d", ft_result);
}*/
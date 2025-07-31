/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:48:24 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/02 18:26:04 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c > 64 && c < 91)
		return (c + 32);
	else
		return (c);
}
/*
int main()
{
    int i = 91;
    int result = tolower(i);
    int ft_result = ft_tolower(i);
    printf("%d", result);
    printf("\n%d", ft_result);
}*/
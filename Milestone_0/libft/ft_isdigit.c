/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:38:28 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/04 16:40:20 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (2048);
	else
		return (0);
}
/*
int main()
{
    int i = 47;
    int result = isdigit(i);
    int ft_result = ft_isdigit(i);
    printf("%d", result);
    printf("\n%d", ft_result);
}*/
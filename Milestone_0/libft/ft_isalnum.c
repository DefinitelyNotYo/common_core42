/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:41:52 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/04 16:40:29 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isdigit(c) == 2048 || ft_isalpha(c) == 1024)
		return (8);
	else
		return (0);
}
/*
int main()
{
    int i = 48;
    int result = isalnum(i);
    int ft_result = ft_isalnum(i);
    printf("%d", result);
    printf("\n%d", ft_result);
}*/
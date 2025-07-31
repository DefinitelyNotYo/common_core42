/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:04:33 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/04 16:40:40 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	i;
	int	result;
	int	sign;

	sign = 0;
	result = 0;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] < 14 && nptr[i] > 8))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = 1;
	while (nptr[i] > 47 && nptr[i] < 58)
		result = result * 10 + (nptr[i++] - 48);
	if (sign)
		return (-1 * result);
	else
		return (result);
}
/*
int main()
{
    const char *str = "  -46\b9 \n5d6";
    int result = atoi(str);
    int ft_result = ft_atoi(str);
    printf("%d\n", result);
    printf("%d", ft_result);    
}*/
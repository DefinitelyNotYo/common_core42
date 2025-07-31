/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 17:15:21 by yoherfan          #+#    #+#             */
/*   Updated: 2025/04/14 17:19:25 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}
/*
int main()
{
    char i[100] = "";
    int result = strlen(i);
    int ft_result = ft_strlen(i);
    printf("%d", result);
    printf("\n%d", ft_result);
}*/
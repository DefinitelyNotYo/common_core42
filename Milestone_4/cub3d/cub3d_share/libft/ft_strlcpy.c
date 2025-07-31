/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:28:20 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/09 14:48:07 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <bsd/string.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (i < size - 1 && src[i] != '\0')
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i] != '\0')
		i++;
	return (i);
}
/*
int main()
{
	char	string_dst[15] = "";
	size_t	res;
	int	i = 0;
	printf("%s\n", string_dst);
	res = ft_strlcpy(string_dst, "", 5);
	res = strlcpy(string_dst, "", 5);
	printf("%zu\n", res);
	while (string_dst[i++])
		printf("\n%c", string_dst[i]);
	return (0);
}*/
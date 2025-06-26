/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 17:01:37 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/11 15:10:35 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *lil, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (lil[i] == '\0')
		return ((char *)big);
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		while (big[j + i] == lil[j] && i + j < len && lil[j] != '\0')
			j++;
		if (lil[j] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
/*
int main()
{
	const char str1[100] = "casale";
    const char str2[100] = "";
	char *res = ft_strnstr(str1, str2, 1);
	printf("%s\n", res);
}*/
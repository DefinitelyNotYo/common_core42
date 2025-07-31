/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:33:18 by yoherfan          #+#    #+#             */
/*   Updated: 2025/04/16 12:37:57 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = ft_calloc(j + 1, sizeof(char));
	while (++i < j + 1)
		((unsigned char *)str)[i] = '\0';
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		str[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str[j++] = s2[i++];
	str[j] = '\0';
	return (str);
}

/*
int main()
{
	char string1[100] = "ca";
	char string2[100] = "ne";
	char *res;
	
	res = ft_strjoin((char const *)string1, (char const *)string2);
	printf("%s", res);
}*/

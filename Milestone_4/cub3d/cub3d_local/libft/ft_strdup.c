/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:32:29 by yoherfan          #+#    #+#             */
/*   Updated: 2025/04/18 16:59:37 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	int		len;
	int		i;

	if (s == NULL)
		return (NULL);
	len = ft_strlen((char *)s);
	i = -1;
	str = (char *)ft_calloc(sizeof(char), len + 1);
	if (!str)
		return (NULL);
	while (s[++i] != '\0')
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}
/*
int main()
{
	char	string1[4] = "ciao";
	char	*string2;
	
	string2 = ft_strdup(string1);
	printf("%s", string2);
}*/
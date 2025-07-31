/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:09:41 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/04 16:35:43 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = -1;
	if ((int)start > (int)ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	str = malloc(sizeof(char) * len + 1);
	while (++i < len + 1)
		((unsigned char *)str)[i] = '\0';
	if (!str)
		return (NULL);
	i = 0;
	while (s[i + start] != '\0' && i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
int main()
{
	char string1[100] = "lorem ipsum dolor sit amet";
	char *string2;

	string2 = ft_substr(string1, 400, 20);
	printf("%s", string2);
}*/
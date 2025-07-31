/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 15:37:16 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/04 16:37:15 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	str = ft_calloc(ft_strlen(s) + 1, 1);
	i = -1;
	while (s[++i] != '\0')
		str[i] = f(i, s[i]);
	return (str);
}

char	set_to_a(unsigned int i, char c)
{
	(void)i;
	c = 97;
	return (c);
}
/*
int main()
{
	char *prova = "ciao";
	printf("%s\n", prova);
	prova = ft_strmapi((char const *)prova, set_to_a);
	printf("%s", prova);
}*/
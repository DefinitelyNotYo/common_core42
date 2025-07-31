/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:50:29 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/04 16:38:25 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	if (s[i] == c)
		return ((char *)&s[i]);
	if (s[i] == '\0')
		return (NULL);
	else
		return ((char *)&s[i]);
}
/*
int main()
{
	const char str[] = "";
	const char *substring1 = ft_strchr(str, '\0');
	const char *substring1 = strchr(str, '\0');
	(void)substring1;
	printf("%s\n", substring1);
}*/
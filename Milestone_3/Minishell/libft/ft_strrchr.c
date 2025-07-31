/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:10:15 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/04 16:36:33 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;
	int	pointer;
	int	toggle;

	i = 0;
	pointer = 0;
	toggle = 0;
	if (c == '\0')
		return ((char *)&s[ft_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			pointer = i;
			toggle = 1;
		}
		i++;
	}
	if (toggle == 0)
		return (NULL);
	return ((char *)&s[pointer]);
}
/*
int main()
{
	const char *str = "casale";
	const char *substring1 = ft_strrchr(str, 's');
	printf("%s", substring1);
}*/

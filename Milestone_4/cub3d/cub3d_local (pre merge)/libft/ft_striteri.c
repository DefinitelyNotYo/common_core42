/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 16:23:22 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/04 17:15:58 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;

	i = -1;
	while (s[++i] != '\0')
		f(i, &s[i]);
}
/*
static void	set_to_a(unsigned int i, char *s)
{
	(void)i;
	s[0] = 97;
}

int main()
{
	char prova[100] = "ciaooooooooooooooooooo";
	printf("%s\n", prova);
	ft_striteri(prova, set_to_a);
	printf("%s", prova);
}*/
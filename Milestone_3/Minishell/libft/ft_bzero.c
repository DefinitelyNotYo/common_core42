/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 16:48:00 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/04 16:40:36 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
		((unsigned char *)s)[i] = '\0';
	return (s);
}
/*int	main()
{
	size_t	n = 2;
	char	s1[5]= "ciao";
	char	s2[5]= "ciao";
	printf("%s\n", s1);
	printf("%s\n", s2);
	
	bzero(s2, n);
	ft_bzero(s1, n);
	
	printf("%s\n", &s1[2]);
	printf("%s\n", &s2[2]);
}*/
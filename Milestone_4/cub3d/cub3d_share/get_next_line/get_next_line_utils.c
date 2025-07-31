/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:35:44 by yoherfan          #+#    #+#             */
/*   Updated: 2025/07/21 16:41:06 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;
	size_t	i;

	pointer = malloc(nmemb * size);
	if (!pointer)
		return (NULL);
	i = -1;
	while (++i < nmemb * size)
		((unsigned char *)pointer)[i] = '\0';
	return (pointer);
}


int	check_newline(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

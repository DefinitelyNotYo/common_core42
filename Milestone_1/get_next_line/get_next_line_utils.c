/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:35:44 by yoherfan          #+#    #+#             */
/*   Updated: 2025/01/14 17:39:23 by yoherfan         ###   ########.fr       */
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

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = ft_calloc(j + 1, 1);
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
	free(s1);
	return (str);
}

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
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

char	*ft_strdup(char *s)
{
	char	*str;
	int		len;
	int		i;

	len = ft_strlen((char *)s);
	i = -1;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	while (s[++i] != '\0')
		str[i] = s[i];
	str[i] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:12:02 by yoherfan          #+#    #+#             */
/*   Updated: 2025/04/04 14:16:11 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		i;
	int		j;

	i = -1;
	j = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	str = malloc(sizeof(char) * j + 1);
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

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (s1 == NULL && s2 != NULL)
		return (-1);
	if (s1 != NULL && s2 == NULL)
		return (-1);
	if (s1 == NULL && s2 == NULL)
		return (-1);
	while (i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}

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

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_jolly_p(t_pathfinder *p, char *cmd)
{
	p->split_cmd = ft_split(cmd, ' ');
	p->i = -1;
	p->path = NULL;
}

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

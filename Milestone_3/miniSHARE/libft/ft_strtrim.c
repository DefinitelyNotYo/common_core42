/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 15:43:38 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/06 14:59:25 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_char(char const *s, char c)
{
	int	i;

	i = -1;
	while (s[++i] != '\0')
		if (s[i] == c)
			return (1);
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		len;
	char	*str;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	j = ft_strlen(s1);
	while (check_char(set, s1[i]) == 1)
		i++;
	if (i == (int)ft_strlen(s1))
		return (ft_strdup(""));
	while (check_char(set, s1[j - 1]) == 1)
		j--;
	len = (int)ft_strlen(s1) - i - ((int)ft_strlen(s1) - j);
	str = malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (j < len)
		str[j++] = s1[i++];
	return (str[j] = '\0', str);
}
/*
int main()
{
	char *s = "aaaaaaaaaaaaaaaaaaa";
	char *set = "a";
	char *s1;
	s1 = ft_strtrim((char const *)s, set);
	free (s1);
	printf("%s", s1);
}*/
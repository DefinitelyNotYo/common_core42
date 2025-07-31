/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 15:35:44 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/17 17:17:07 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strjoin_g(char *s1, char *s2)
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

int	ft_strlen_g(char *s)
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

	if (str == NULL)
		return (0);
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

int	ft_here_doc(char *lim, t_parameters *p)
{
	int		fd;
	int		std;

	std = dup(0);
	dup2(p->read_0, 0);
	dup2(p->write_1, 1);
	signal(SIGINT, heredoc_sigint);
	signal(SIGQUIT, SIG_IGN);
	fd = open(".heredoc", O_RDWR | O_TRUNC | O_CREAT, 0777);
	ft_here_doc_exe(p, lim, fd, std);
	close(fd);
	close(std);
	fd = open(".heredoc", O_RDWR, 0777);
	return (fd);
}

int	ft_find_quote(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '\'' || str[i] == '\"')
			return (1);
	}
	return (0);
}

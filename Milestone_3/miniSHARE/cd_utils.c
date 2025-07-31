/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:23:16 by cciapett          #+#    #+#             */
/*   Updated: 2025/06/05 13:59:27 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strlen_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		i++;
	}
	return (i);
}

char	*ft_memcopy(char *src, int n)
{
	int		i;
	char	*dest;

	i = -1;
	dest = ft_calloc(sizeof(char), n + 1);
	if (!dest)
		return (NULL);
	while (++i < n && src[i] != '\0')
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

int	ft_strlen_3d_matrix(char ***matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		i++;
	}
	return (i);
}

int	ft_strlen_arg(t_arg *matrix)
{
	int	i;

	i = 0;
	while (matrix[i].arg != NULL)
	{
		i++;
	}
	return (i);
}

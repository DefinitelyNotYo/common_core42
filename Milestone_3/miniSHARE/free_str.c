/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 18:37:46 by yoherfan          #+#    #+#             */
/*   Updated: 2025/04/09 17:29:14 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_freejoin(char *str1, char *str2)
{
	char	*temp;

	if (str1 != NULL)
	{
		temp = ft_strjoin(str1, str2);
		free (str1);
		str1 = ft_strdup(temp);
		free(temp);
	}
	return (str1);
}

char	*ft_freedup(char *str1, char *str2)
{
	char	*temp;

	if (str1 != NULL)
	{
		temp = ft_strdup(str2);
		free (str1);
		str1 = ft_strdup(temp);
		free(temp);
	}
	return (str1);
}

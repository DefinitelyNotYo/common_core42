/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/08 14:56:07 by cciapett          #+#    #+#             */
/*   Updated: 2025/04/18 17:07:20 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_copy_matrix(char **env)
{
	char	**env_copy;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen_matrix(env);
	env_copy = (char **)ft_calloc((len + 1), sizeof(char *));
	if (!env_copy)
		return (NULL);
	while (env[i] != NULL)
	{
		env_copy[i] = ft_strdup(env[i]);
		i++;
	}
	return (env_copy);
}

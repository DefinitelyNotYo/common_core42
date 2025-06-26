/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_order.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/06 16:04:06 by cciapett          #+#    #+#             */
/*   Updated: 2025/06/14 11:36:47 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

int	ft_order(char ***env_copy)
{
	int	i;
	int	j;

	i = -1;
	while ((*env_copy)[++i + 1] != NULL)
	{
		j = -1;
		while ((*env_copy)[i][++j] != '\0')
		{
			if ((*env_copy)[i][j] < (*env_copy)[i + 1][j])
				break ;
			else if ((*env_copy)[i][j] == (*env_copy)[i + 1][j])
				continue ;
			else
				return (1);
		}
	}
	return (0);
}

void	ft_bubble_sort(char ***env_copy)
{
	int		i;
	char	*env_copy_str;

	while (ft_order(env_copy) == 1)
	{
		i = -1;
		while ((*env_copy)[++i + 1] != NULL)
		{
			if (ft_strcmp((*env_copy)[i], (*env_copy)[i + 1]) > 0)
			{
				env_copy_str = ft_strdup((*env_copy)[i]);
				free((*env_copy)[i]);
				(*env_copy)[i] = ft_strdup((*env_copy)[i + 1]);
				free((*env_copy)[i + 1]);
				(*env_copy)[i + 1] = ft_strdup(env_copy_str);
				free(env_copy_str);
			}
		}
	}
}

int	ft_check_existence_export(char ***env_copy, char *export_str)
{
	int	i;

	i = -1;
	while ((*env_copy)[++i] != NULL)
	{
		if (ft_strncmp((*env_copy)[i], export_str, ft_strlen(export_str)) == 0 \
		&& (ft_strlen(export_str) == ft_strlen((*env_copy)[i]) \
		|| (*env_copy)[i][ft_strlen(export_str)] == '='))
			return (1);
	}
	return (0);
}

void	ft_search_plus(char *str, char ***env_copy, int *index)
{
	int	i;
	int	toggle;

	i = 0;
	toggle = 0;
	while (str[i] != '\0' && str[i + 1] != '\0')
	{
		if (str[i] == '+' && str[i + 1] == '=')
		{
			toggle = 1;
			ft_add_value(env_copy, str, i, index);
			break ;
		}
		else if (str[i] != '+' && str[i + 1] == '=')
		{
			toggle = 1;
			ft_substitute_value(env_copy, str, i + 1, index);
			break ;
		}
		i++;
	}
	if (toggle == 0 && ft_check_existence_export(env_copy, str) == 0)
		(*env_copy)[index[0] + index[2]] = ft_strdup(str);
}

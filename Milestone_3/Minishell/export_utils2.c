/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:33:28 by cciapett          #+#    #+#             */
/*   Updated: 2025/06/16 16:10:08 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_create_value_eq(char ***env_copy, char *str, int pos, int *index)
{
	char	*name;
	char	*value;
	char	*temp;
	int		i;

	i = 0;
	value = NULL;
	name = ft_memcopy(str, pos);
	value = ft_memcopy(str + pos + 1, ft_strlen(str) - pos);
	temp = ft_strjoin(name, "=");
	(*env_copy)[index[0] + index[2]] = ft_strjoin(temp, value);
	free(temp);
	if (name != NULL)
		free(name);
	if (value != NULL)
		free(value);
}

void	ft_create_value_plus(char ***env_copy, char *str, int pos, int *index)
{
	char	*name;
	char	*value;
	char	*temp;
	int		i;

	i = 0;
	value = NULL;
	name = ft_memcopy(str, pos - 1);
	value = ft_memcopy(str + pos + 1, ft_strlen(str) - pos);
	temp = ft_strjoin(name, "=");
	(*env_copy)[index[0] + index[2]] = ft_strjoin(temp, value);
	if (temp != NULL)
		free(temp);
	if (name != NULL)
		free(name);
	if (value != NULL)
		free(value);
}

void	ft_copy_str(char *name, char *value, char **env_copy_str)
{
	char	*temp;
	char	*temp1;

	temp1 = ft_strjoin(name, "=");
	temp = ft_strjoin(temp1, value);
	if (temp1 != NULL)
		free(temp1);
	if (*env_copy_str != NULL)
		free(*env_copy_str);
	*env_copy_str = ft_strdup(temp);
	if (temp != NULL)
		free(temp);
}

void	ft_copy_str2(char *value, char **env_copy_str)
{
	char	*temp;

	temp = ft_strjoin(*env_copy_str, value);
	if (*env_copy_str != NULL)
		free(*env_copy_str);
	*env_copy_str = ft_strdup(temp);
	if (temp != NULL)
		free(temp);
}

//pos posizione del =
void	ft_substitute_value(char ***env_copy, char *str, int pos, int *index)
{
	char	*name;
	char	*value;
	int		i;

	i = -1;
	name = ft_memcopy(str, pos);
	value = ft_memcopy(str + pos + 1, ft_strlen(str) - pos);
	while ((*env_copy)[++i] != NULL)
	{
		if (ft_strncmp((*env_copy)[i], name, ft_strlen(name)) == 0 \
		&& ((*env_copy)[i][ft_strlen(name)] == '=' \
		|| (*env_copy)[i][ft_strlen(name)] == '\0'))
		{
			ft_copy_str(name, value, &(*env_copy)[i]);
			break ;
		}
	}
	if ((*env_copy)[i] == NULL)
		ft_create_value_eq(env_copy, str, pos, index);
	if (name != NULL)
		free(name);
	if (value != NULL)
		free(value);
}

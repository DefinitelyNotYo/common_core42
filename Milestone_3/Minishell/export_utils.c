/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 13:42:54 by cciapett          #+#    #+#             */
/*   Updated: 2025/06/13 16:48:31 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_display_export(char **temp, char **str_copy)
{
	if (*temp != NULL)
		free(*temp);
	ft_putstr_fd(*str_copy, 1);
	ft_putstr_fd("\n", 1);
	if (*str_copy != NULL)
		free(*str_copy);
}

//i[2] e' un toggle
void	ft_export_add_quotes(char *str)
{
	int		i[3];
	char	*temp;
	char	*str_copy;

	i[0] = 0;
	i[1] = -1;
	i[2] = 0;
	temp = ft_strjoin("declare -x ", str);
	str_copy = ft_calloc(ft_strlen(temp) + 1 + 2, sizeof(char));
	if (!str_copy)
		return ;
	while (temp[++i[1]] != '\0')
	{
		str_copy[i[0]] = temp[i[1]];
		if (temp[i[1]] == '=' && i[2] == 0)
		{
			i[2] = 1;
			i[0]++;
			str_copy[i[0]] = '"';
		}
		i[0]++;
	}
	if (i[2] == 1)
		str_copy[i[0]] = '"';
	ft_display_export(&temp, &str_copy);
}

//mtx1->env_copy
//mtx2-> env_copy_temp
//matrix->matrix
void	ft_init_export_mtx(char ***mtx1, char ***mtx2, char ***matrix, int *i)
{
	(*mtx2) = ft_copy_matrix(*mtx1);
	ft_free_matrix(*mtx1, 0);
	*i = ft_strlen_matrix(*mtx2) + ft_strlen_matrix(*matrix) - 1;
	(*mtx1) = (char **)ft_calloc((*i) + 1, sizeof(char *));
}

int	ft_avoid_plus(char *str)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
	{
		if (str[i] == '+' && str[i + 1] != '=')
			return (1);
	}
	return (0);
}

int	ft_check_export(char *str, t_parameters *p)
{
	char	*str_err;
	char	*temp;

	str_err = NULL;
	temp = NULL;
	if (ft_isalpha_env(str[0]) != 1024 || ft_avoid_plus(str) == 1 || \
	ft_faya(str, "/") == 1)
	{
		temp = ft_strjoin("bash: export: '", str);
		str_err = ft_strjoin(temp, "': not a valid identifier\n");
		ft_putstr_fd(str_err, 2);
		if (temp != NULL)
			free(temp);
		if (str_err != NULL)
			free(str_err);
		p->dollar = 1;
		return (1);
	}
	return (0);
}

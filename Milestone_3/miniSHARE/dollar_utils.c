/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 12:19:47 by cciapett          #+#    #+#             */
/*   Updated: 2025/06/23 14:24:03 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_dollar(char *str)
{
	int		i;
	int		len;
	char	*str_aft;

	i = 0;
	len = 0;
	while (str[i] != '\0' && ft_isalnum_env(str[i]) != 0)
	{
		len++;
		i++;
	}
	str_aft = ft_memcopy(str, len);
	return (str_aft);
}

char	*ft_after_dollar(char *str)
{
	int		i;
	int		len;
	char	*str_aft;

	i = 0;
	len = 0;
	while (str[i] != '\0')
	{
		len++;
		i++;
	}
	str_aft = ft_memcopy(str, len);
	return (str_aft);
}

void	ft_copy_number(char **str, char *nbr, int *j)
{
	int	i;

	i = 0;
	while (nbr[i] != '\0')
	{
		(*str)[(*j)++] = nbr[i++];
	}
}

void	ft_init_doll(char **str, char **str_itoa, t_parameters *p, char **temp)
{
	*str_itoa = ft_itoa(p->dollar);
	*temp = ft_strdup((*str));
	if (*str != NULL)
		free(*str);
	(*str) = ft_calloc(ft_strlen(*temp) + ft_strlen(*str_itoa) + 2, \
	sizeof(char));
}

void	ft_search_questionmark(char **str, t_parameters *p)
{
	int		i[2];
	char	*str_itoa;
	char	*temp;

	i[0] = 0;
	i[1] = 0;
	ft_init_doll(str, &str_itoa, p, &temp);
	while (temp[i[0]] != '\0')
	{
		if (temp[i[0]] == '$' && temp[i[0] + 1] == '?')
		{
			ft_copy_number(str, str_itoa, &i[1]);
			i[1]++;
			i[0] += 2;
		}
		else
		{
			(*str)[i[1]] = temp[i[0]];
			i[0]++;
			i[1]++;
		}
	}
	free (temp);
	free (str_itoa);
}

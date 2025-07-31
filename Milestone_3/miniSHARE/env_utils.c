/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 15:35:28 by cciapett          #+#    #+#             */
/*   Updated: 2025/06/06 15:45:43 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_condition_env(char *env_copy_str, char *str_pwd)
{
	if (ft_strncmp(str_pwd, env_copy_str, ft_strlen(str_pwd)) == 0 \
	&& env_copy_str[ft_strlen(str_pwd)] == '=')
		return (0);
	else
		return (1);
}

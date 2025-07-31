/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cciapett <cciapett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/14 11:23:37 by cciapett          #+#    #+#             */
/*   Updated: 2025/07/17 14:45:00 by cciapett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_isalpha_env(int c)
{
	if ((c > 64 && c < 91) || (c > 96 && c < 123) || (c == 95))
		return (1024);
	else
		return (0);
}

int	ft_invalid_identifier(char *str)
{
	int	i;
	int	toggle;

	i = -1;
	toggle = 0;
	while (str[++i] != '\0' && toggle == 0)
	{
		if (str[i] == '+' && str[i + 1] == '=')
		{
			i++;
			toggle = 1;
		}
		else if (str[i] == '=')
			toggle = 1;
		if (ft_isalnum_env(str[i]) == 0 && ft_isdigit(str[i]) == 0 \
		&& toggle == 0)
			return (1);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_string_handle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 14:28:03 by yoherfan          #+#    #+#             */
/*   Updated: 2025/02/11 18:17:04 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	split_exe(char *str, t_stack **s, int i, int j)
{
	char		*dummy;
	long long	num;

	dummy = ft_substr(str, i + 1, j - i);
	if (is_number(dummy) == 1)
	{
		num = ft_atoi(dummy);
		if (check_overflows(num) == 1)
			ft_add_node(s, ft_newnode(num));
		else
			return (free(dummy), 0);
	}
	else
		return (free(dummy), 0);
	free (dummy);
	return (1);
}

int	split_v2(char *str, t_stack **s)
{
	int		i;
	int		j;
	int		toggle;

	i = ft_strlen(str);
	j = 0;
	toggle = 0;
	while (str[--i] != '\0')
	{
		if (str[i] != ' ' && toggle == 0)
		{
			toggle = 1;
			j = i;
		}
		if (str[i] == ' ' && toggle == 1)
		{
			toggle = 0;
			if (split_exe(str, s, i, j) == 0)
				return (0);
		}
	}
	if (toggle == 1)
		if (split_exe(str, s, i, j) == 0)
			return (0);
	return (1);
}

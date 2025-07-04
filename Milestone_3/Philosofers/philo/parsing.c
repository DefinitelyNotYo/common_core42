/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 17:22:47 by yoherfan          #+#    #+#             */
/*   Updated: 2025/07/04 18:48:07 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

int	parse_inputs(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc < 5 || argc > 6)
		return (printf("Invalid number of arguments\n"), -1);
	while (++i < argc)
		if (contains_not_numbers(argv[i]) == -1 || argv[i][0] == '\0')
			return (printf("Invalid arguments\n"), -1);
	if (ft_atoll(argv[1]) < 1)
		return (printf("Invalid number of philosofers\n"), -1);
	if (ft_atoll(argv[2]) < 0 || ft_atoll(argv[3]) < 0 || \
		ft_atoll(argv[4]) < 0)
		return (printf("Invalid times\n"), -1);
	if (argc == 6)
		if (ft_atoll(argv[5]) < 1)
			return (printf("Invalid max meals\n"), -1);
	return (1);
}

int	contains_not_numbers(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	return (1);
}

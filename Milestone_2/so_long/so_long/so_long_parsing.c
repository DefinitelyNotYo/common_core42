/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:04:50 by yoherfan          #+#    #+#             */
/*   Updated: 2025/03/04 17:11:45 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_map(void *params)
{
	t_param	*dummy;

	dummy = (t_param *)params;
	if (ft_check_objects(params) == 0)
	{
		write(1, "Error\nInvalid objects\n", 22);
		ft_clean_map(dummy->map, dummy->map_rows);
		exit (0);
	}
	if (ft_check_map_form(params) == 0 || ft_inspect_map(params) == 0)
	{
		write(1, "Error\nInvalid map form\n", 23);
		ft_clean_map(dummy->map, dummy->map_rows);
		exit (0);
	}
	if (ft_floodfill(params) == 0)
	{
		write(1, "Error\nInvalid flood\n", 20);
		ft_clean_map(dummy->map, dummy->map_rows);
		exit (0);
	}
}

int	ft_check_objects(void *params)
{
	t_param	*dummy;
	int		items[2];
	int		i;
	int		j;

	dummy = (t_param *)params;
	items[0] = 0;
	items[1] = 0;
	i = -1;
	while (++i < dummy->map_rows)
	{
		j = -1;
		while (++j < ft_strlen(dummy->map[i]))
		{
			if (dummy->map[i][j] == 'P' || dummy->map[i][j] == 'E')
				items[0]++;
			if (dummy->map[i][j] == 'C')
				items[1]++;
			if (ft_validate_objects(dummy->map[i][j]) == 0)
				return (0);
		}
	}
	if (items[0] != 2 || items[1] < 1)
		return (0);
	return (1);
}

int	ft_validate_objects(char c)
{
	if (c != '1' && c != '0' && c != 'P' && c != 'E' && c != 'C' && c != '\n')
		return (0);
	return (1);
}

int	ft_check_format(char *path)
{
	int	lenght;

	lenght = ft_strlen(path);
	if (path[lenght - 4] != '.')
		return (0);
	if (path[lenght - 3] != 'b')
		return (0);
	if (path[lenght - 2] != 'e')
		return (0);
	if (path[lenght - 1] != 'r')
		return (0);
	return (1);
}

int	ft_check_map_form(void *params)
{
	t_param	*dummy;
	int		i;
	int		j;
	int		lenght;

	dummy = (t_param *)params;
	lenght = ft_strlen_2(dummy->map[0]);
	i = -1;
	while (++i < dummy->map_rows)
		if (ft_strlen_2(dummy->map[i]) != lenght)
			return (0);
	i = -1;
	while (++i < dummy->map_rows)
	{
		j = -1;
		while (++j < ft_strlen_2(dummy->map[i]))
			if (i == 0 || j == 0 || i == dummy->map_rows - 1 || \
				j == ft_strlen_2(dummy->map[i]) - 1)
				if (dummy->map[i][j] != '1')
					return (0);
	}
	return (1);
}

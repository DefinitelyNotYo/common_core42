/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 14:32:40 by yoherfan          #+#    #+#             */
/*   Updated: 2025/07/31 17:05:09 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	closed_dx(char *line)
{
	if (line[(int)ft_strlen(line) - 1] == '1' || line[(int)ft_strlen(line) - 1] == ' ')
		return (0);
	else
		return (-1);	
}

int	closed_sx(char *line)
{
	if (line[0] == '1' || line[0] == ' ')
		return (0);
	else
		return (-1);	
}

int	closed_updown(t_input *in)
{
	int	i;
	int	j;
	int	h;
	char c;

	i = -1;
	j = 0;
	h = 0;		
	while (++i < in->map_len)
	{
		if (in->map[0][i] != '1' && in->map[0][i] != ' ' && in->map[0][i] != '\0')
			return (0);
		j = 0;
		c = in->map[j][i];
		while (in->map[j] != NULL && (int)ft_strlen(in->map[j]) != 0)
		{
			if ((in->map[j][i] == '\0' && c != '1' && c != ' ' && c != '\0') \
			|| (in->map[j][i] == '0' && c != '1' && c != ' ' && c != '0'))
				return (0);
			c = in->map[j][i];
			j++;			
		}
	}
	return (1);
}

int	is_closed(t_input *in)
{
	int i;
	int	j;
	int	lim[3];

	i = -1;
	lim[2] = 0;
	if (closed_updown(in) == 0)
		return (0);
	while (in->map[++i] != NULL)
	{
		if ((int)ft_strlen(in->map[i]) == 0)
		{
			lim[2] = 1;
			continue;
		}
		if ((int)ft_strlen(in->map[i]) != 0 && lim[2] == 1)
			return (0);
		lim[0] = closed_sx(in->map[i]);
		lim[1] = closed_dx(in->map[i]);
		if (lim[0] == -1 || lim[1] == -1)
			return (0);
		j = -1;
		while (in->map[i][++j] != '\0')
			if (in->map[i][j] == ' ')
				in->map[i][j] = '1';
		// printf("R: %s\n", in->map[i]); --Commentata prima delle vacanze--
	}
	return (1);
}

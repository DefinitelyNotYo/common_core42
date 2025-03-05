/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:45:27 by yoherfan          #+#    #+#             */
/*   Updated: 2025/03/04 17:17:40 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_strlen_2(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

int	ft_putnbr(int n, int fd, int len)
{
	char	value;

	len = 0;
	if (n >= 10 || n <= -10)
		len += ft_putnbr(n / 10, fd, len);
	value = (n % 10) + '0';
	len += write (fd, &value, 1);
	return (len);
}

void	ft_put_move(void *params, int toggle)
{
	t_param	*dummy;

	dummy = (t_param *)params;
	if (toggle == 1)
		dummy->moves++;
	ft_putnbr(dummy->moves, 1, 0);
	write(1, "\n", 1);
}

int	ft_inspect_map(void *params)
{
	t_param	*dummy;
	int		i;
	int		j;
	int		count;

	count = 0;
	dummy = (t_param *)params;
	i = 0;
	while (i < dummy->map_rows)
	{
		j = 0;
		while (dummy->map[i][j] != '\0' && dummy->map[i][j] != '\n')
			j++;
		if (dummy->map[i][j] == '\n')
			count++;
		i++;
	}
	if (count == dummy->map_rows)
		return (0);
	return (1);
}

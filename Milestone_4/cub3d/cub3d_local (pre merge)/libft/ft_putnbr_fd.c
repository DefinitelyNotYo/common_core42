/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 17:46:26 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/04 16:38:59 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr(int n, int fd)
{
	char	value;

	if (n >= 10 || n <= -10)
		ft_putnbr(n / 10, fd);
	else
		if (n < 0)
			write(fd, "-", 1);
	if (n < 0)
		value = ((n % 10) * -1) + '0';
	else
		value = (n % 10) + '0';
	write (fd, &value, 1);
}

void	ft_putnbr_fd(int n, int fd)
{
	ft_putnbr(n, fd);
}
/*
int main()
{
	int	n = 0;
	ft_putnbr_fd(n, 1);
}*/
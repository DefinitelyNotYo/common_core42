/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lhima <lhima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 15:22:27 by yoherfan          #+#    #+#             */
/*   Updated: 2025/01/02 15:29:44 by lhima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar_fd(char c, int fd)
{
	int	len;

	len = 0;
	len = write(fd, &c, 1);
	return (len);
}

int	ft_putstr_fd(char *s, int fd, int toggle)
{
	int	len;
	int	i;

	if (!s)
	{
		len = 0;
		len = 6;
		write(fd, "(null)", len);
		return (len);
	}
	if (toggle == 0)
	{
		len = 0;
		len = ft_putstr_fd(s, 1, 1);
		write(fd, s, len);
		return (len);
	}
	else
	{
		i = 0;
		while (s[i] != '\0')
			i++;
		return (i);
	}
}

int	ft_putnbr(int n, int fd, int len, int toggle)
{
	char	value;

	len = 0;
	if (n >= 10 || n <= -10)
		len += ft_putnbr(n / 10, fd, len, toggle);
	else
		if (n < 0)
			if (toggle == 0)
				len += write(fd, "-", 1);
	if (n < 0)
		value = ((n % 10) * -1) + '0';
	else
		value = (n % 10) + '0';
	len += write (fd, &value, 1);
	return (len);
}

int	ft_putaddress(void *address)
{
	int	len;

	if (address == NULL)
	{
		return (ft_printf("(nil)"));
	}
	len = write(1, "0x", 2);
	len += ft_putnbr_base((unsigned long)address, "0123456789abcdef", 0);
	return (len);
}

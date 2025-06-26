/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:51:30 by yoherfan          #+#    #+#             */
/*   Updated: 2025/05/14 17:31:06 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_check(int i, va_list ls, const char *r_key)
{
	int	len;

	len = 0;
	if (r_key[i] == '%' && r_key[i + 1] == 'c')
		len += ft_putchar_fd(va_arg(ls, int), 1);
	else if (r_key[i] == '%' && r_key[i + 1] == 's')
		len += ft_putstr_fd(va_arg(ls, char *), 1, 0);
	else if (r_key[i] == '%' && r_key[i + 1] == 'd')
		len += ft_putnbr(va_arg(ls, int), 1);
	else if (r_key[i] == '%' && r_key[i + 1] == 'i')
		len += ft_putnbr(va_arg(ls, int), 1);
	else if (r_key[i] == '%' && r_key[i + 1] == '%')
		len += ft_putchar_fd('%', 1);
	else if (r_key[i] == '%' && r_key[i + 1] == 'u')
		len += ft_putnbr_base(va_arg(ls, unsigned int), "0123456789", 0);
	else if (r_key[i] == '%' && r_key[i + 1] == 'p')
		len += ft_putaddress(va_arg(ls, void *));
	else if (r_key[i] == '%' && r_key[i + 1] == 'X')
		len += ft_putnbr_base(va_arg(ls, unsigned int), "0123456789ABCDEF", 0);
	else if (r_key[i] == '%' && r_key[i + 1] == 'x')
		len += ft_putnbr_base(va_arg(ls, unsigned int), "0123456789abcdef", 0);
	return (len);
}

int	ft_printf(const char *r_key, ...)
{
	va_list	strings;
	int		i;
	int		len;

	if (!r_key)
		return (-1);
	va_start(strings, r_key);
	i = 0;
	len = 0;
	while (r_key[i] != '\0')
	{
		if (r_key[i] == '%')
		{
			len += ft_printf_check(i, strings, r_key);
			i++;
		}
		else
			len += write(1, &r_key[i], 1);
		i++;
	}
	return (len);
}

int	check_base(char *base)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	len = ft_putstr_fd(base, 1, 1);
	if (len < 2)
		return (0);
	while (base[i] != '\0')
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_exe(unsigned long nbr, char *base, int len)
{
	if (nbr == 0)
		return (0);
	else
	{
		len += ft_putnbr_exe(nbr / ft_putstr_fd(base, 1, 1), base, len);
		write(1, &base[nbr % ft_putstr_fd(base, 1, 1)], 1);
		len++;
	}
	return (len);
}

int	ft_putnbr_base(unsigned long x, char *base, int len)
{
	if (check_base(base) == 1)
	{
		if (x == 0)
		{
			write(1, &base[0], 1);
			len++;
			return (len);
		}
		else
			len += ft_putnbr_exe(x / ft_putstr_fd(base, 1, 1), base, len);
		write(1, &base[x % ft_putstr_fd(base, 1, 1)], 1);
		len++;
	}
	return (len);
}
int main()
{
	char *address = "ciao";

	ft_printf("\n----- TEST SENZA FLAG -----\n\n");

	printf("printf:    ");
	printf("prova\n");
	ft_printf("ft_printf: ");
	ft_printf("prova");

	ft_printf("\n\n----- TEST %%c -----\n\n");

	printf("printf:    %c\n", 'c');
	ft_printf("ft_printf: %c", 'c');

	ft_printf("\n\n----- TEST %%s -----\n\n");

	printf("printf:    %s\n", "stringa");
	ft_printf("ft_printf: %s", "stringa");

	ft_printf("\n\n----- TEST %%d -----\n\n");

	printf("printf:    %d\n", -42);
	ft_printf("ft_printf: %d", -42);

	ft_printf("\n\n----- TEST %%i -----\n\n");

	printf("printf:    %i\n", 42);
	ft_printf("ft_printf: %i", 42);

	ft_printf("\n\n----- TEST %% -----\n\n");

	printf("printf:    %%\n");
	ft_printf("ft_printf: %%");

	ft_printf("\n\n----- TEST %%p -----\n\n");

	printf("printf:    %p\n", address);
	ft_printf("ft_printf: %p", address);

	ft_printf("\n\n----- TEST %%u -----\n\n");

	printf("printf:    %u\n", -1);
	ft_printf("ft_printf: %u", -1);

	ft_printf("\n\n----- TEST %%x -----\n\n");

	printf("printf:    %x\n", -12);
	ft_printf("ft_printf: %x", -12);

	ft_printf("\n\n----- TEST %%X -----\n\n");

	printf("printf:    %X\n", -1);
	ft_printf("ft_printf: %X", -1);
}
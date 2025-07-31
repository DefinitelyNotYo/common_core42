/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:01:23 by yoherfan          #+#    #+#             */
/*   Updated: 2024/12/04 16:39:44 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_digit(int n)
{
	int	i;
	int	toggle;

	i = 0;
	toggle = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		toggle = 1;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	if (toggle == 0)
		return (i);
	else
		return (i + 1);
}

char	*print_min(char *s)
{
	s[0] = '-';
	s[1] = '2';
	s[2] = '1';
	s[3] = '4';
	s[4] = '7';
	s[5] = '4';
	s[6] = '8';
	s[7] = '3';
	s[8] = '6';
	s[9] = '4';
	s[10] = '8';
	s[11] = '\0';
	return (s);
}

char	*ft_itoa(int n)
{
	char	*nmbr;
	int		i;
	int		digits;
	int		toggle;

	i = -1;
	digits = check_digit(n);
	nmbr = ft_calloc(digits + 1, 1);
	if (n == -2147483648)
		return (print_min(nmbr));
	if (!nmbr)
		return (NULL);
	if (n < 0)
		toggle = 1;
	if (n < 0)
		n = n * (-1);
	while (++i < digits)
	{
		nmbr[digits - i - 1] = (n % 10) + '0';
		n = n / 10;
	}
	if (toggle == 1)
		nmbr[0] = '-';
	nmbr[i] = '\0';
	return (nmbr);
}
/*
int main()
{
	char	*string;
	string = ft_itoa(0);
	printf("%s", string);
	
}*/
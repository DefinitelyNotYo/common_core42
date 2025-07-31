/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:01:23 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/11 15:08:45 by yoherfan         ###   ########.fr       */
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

//par[0] = toggle, par[1] = digits
char	*ft_itoa(int n)
{
	char	*nmbr;
	int		i;
	int		par[2];

	par[0] = 0;
	i = -1;
	par[1] = check_digit(n);
	nmbr = ft_calloc(par[1] + 1, 1);
	if (n == -2147483648)
		return (print_min(nmbr));
	if (!nmbr)
		return (NULL);
	if (n < 0)
		par[0] = 1;
	if (n < 0)
		n = n * (-1);
	while (++i < par[1])
	{
		nmbr[par[1] - i - 1] = (n % 10) + '0';
		n = n / 10;
	}
	if (par[0] == 1)
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
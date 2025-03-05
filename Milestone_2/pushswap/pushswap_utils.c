/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 15:39:55 by yoherfan          #+#    #+#             */
/*   Updated: 2025/02/11 18:18:28 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*pointer;
	size_t	i;

	pointer = malloc(nmemb * size);
	if (!pointer)
		return (NULL);
	i = -1;
	while (++i < nmemb * size)
		((unsigned char *)pointer)[i] = '\0';
	return (pointer);
}

long long	ft_atoi(const char *nptr)
{
	int			i;
	long long	result;
	int			sign;

	sign = 0;
	result = 0;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] < 14 && nptr[i] > 8))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
		if (nptr[i++] == '-')
			sign = 1;
	while (nptr[i] > 47 && nptr[i] < 58)
		result = result * 10 + (nptr[i++] - 48);
	if (sign)
		return (-1 * result);
	else
		return (result);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = -1;
	if ((int)start > (int)ft_strlen(s))
		return (ft_calloc(1, sizeof(char)));
	str = malloc(sizeof(char) * len + 1);
	while (++i < len + 1)
		((unsigned char *)str)[i] = '\0';
	if (!str)
		return (NULL);
	i = 0;
	while (s[i + start] != '\0' && i < len)
	{
		str[i] = s[i + start];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

// void	ft_putnbr(long long n)
// {
// 	char	value;

// 	if (n >= 10 || n <= -10)
// 		ft_putnbr(n / 10);
// 	else
// 		if (n < 0)
// 			write(1, "-", 1);
// 	if (n < 0)
// 		value = ((n % 10) * -1) + '0';
// 	else
// 		value = (n % 10) + '0';
// 	write (1, &value, 1);
// }

int	ft_abs(int n)
{
	int	result;

	if (n >= 0)
		return (n);
	else
	{
		result = -1 * n;
		return (result);
	}
}

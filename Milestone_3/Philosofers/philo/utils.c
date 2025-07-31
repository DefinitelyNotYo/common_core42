/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:49:58 by yoherfan          #+#    #+#             */
/*   Updated: 2025/07/07 14:56:11 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void	ft_putnbr(long long n, int fd)
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

long long	ft_atoll(char *nptr)
{
	int				i;
	long long		result;
	int				sign;

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

long long	get_time_stamp(void)
{
	struct timeval	time;
	long long		time_stamp;

	gettimeofday(&time, NULL);
	time_stamp = time.tv_sec * 1000L + time.tv_usec / 1000L;
	return (time_stamp);
}

int	check_meals(t_table *table)
{
	int	i;
	int	toggle;

	i = -1;
	toggle = 0;
	while (++i < table->n_philos)
	{
		pthread_mutex_lock(table->philos[i].mute_max_meals);
		if (table->philos[i].rules->notepme == -1)
			return (pthread_mutex_unlock(table->philos[i].mute_max_meals), 0);
		if (table->philos[i].meals != table->philos[i].rules->notepme)
			toggle = 1;
		pthread_mutex_unlock(table->philos[i].mute_max_meals);
	}
	if (toggle == 1)
		return (0);
	else
		return (1);
}

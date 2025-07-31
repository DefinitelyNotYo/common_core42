/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 15:56:46 by yoherfan          #+#    #+#             */
/*   Updated: 2025/07/04 14:57:59 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void	send_message(t_philosofer *philo, int flag)
{
	long long		time_stamp;

	pthread_mutex_lock(philo->mute_alive);
	if (*philo->everybody_lives == 0)
		return (pthread_mutex_unlock(philo->mute_alive), (void)0);
	time_stamp = get_time_stamp() - philo->clock;
	if (flag == 1)
		printf("%lld %d has taken a fork\n", time_stamp, philo->id);
	else if (flag == 2)
		printf("%lld %d is eating\n", time_stamp, philo->id);
	else if (flag == 3)
		printf("%lld %d is sleeping\n", time_stamp, philo->id);
	else if (flag == 4)
		printf("%lld %d is thinking\n", time_stamp, philo->id);
	else if (flag == 5)
		printf("%lld %d died\n", time_stamp, philo->id);
	pthread_mutex_unlock(philo->mute_alive);
}

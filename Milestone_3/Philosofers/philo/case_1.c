/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 15:05:59 by yoherfan          #+#    #+#             */
/*   Updated: 2025/07/04 14:57:13 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void	actions_one(t_philosofer *philo)
{
	pthread_mutex_lock(philo->mute_alive);
	if (*philo->everybody_lives == 0)
		return (pthread_mutex_unlock(philo->mute_alive), (void)0);
	pthread_mutex_unlock(philo->mute_alive);
	pthread_mutex_lock(philo->fork_dx);
	send_message(philo, 1);
	pthread_mutex_unlock(philo->fork_dx);
}

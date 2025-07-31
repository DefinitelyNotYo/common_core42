/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lock.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/04 14:43:12 by yoherfan          #+#    #+#             */
/*   Updated: 2025/07/04 18:40:27 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void	fix_lock(t_philosofer *philo)
{
	pthread_mutex_lock(philo->fork_dx);
	pthread_mutex_lock(philo->fork_sx);
}

void	fix_unlock(t_philosofer *philo)
{
	pthread_mutex_unlock(philo->fork_dx);
	pthread_mutex_unlock(philo->fork_sx);
}

void	lock_fork(t_philosofer *philo)
{
	if (philo->n_philos % 2 == 1)
	{
		if (philo->id - 1 % 2 == 1)
			fix_lock(philo);
		else
		{
			pthread_mutex_lock(philo->fork_sx);
			pthread_mutex_lock(philo->fork_dx);
		}
	}
	else
	{
		if (philo->id % 2 == 1)
		{
			pthread_mutex_lock(philo->fork_dx);
			pthread_mutex_lock(philo->fork_sx);
		}
		else
		{
			pthread_mutex_lock(philo->fork_sx);
			pthread_mutex_lock(philo->fork_dx);
		}
	}
}

void	unlock_fork(t_philosofer *philo)
{
	if (philo->n_philos % 2 == 1)
	{
		if (philo->id - 1 % 2 == 1)
			fix_unlock(philo);
		else
		{
			pthread_mutex_unlock(philo->fork_sx);
			pthread_mutex_unlock(philo->fork_dx);
		}
	}
	else
	{
		if (philo->id % 2 == 1)
		{
			pthread_mutex_unlock(philo->fork_dx);
			pthread_mutex_unlock(philo->fork_sx);
		}
		else
		{
			pthread_mutex_unlock(philo->fork_sx);
			pthread_mutex_unlock(philo->fork_dx);
		}
	}
}

void	death_bell_lock(t_table *table, int i)
{
	long long	millisec;

	pthread_mutex_lock(&table->mute_last_meal[i]);
	millisec = get_time_stamp() - table->philos[i].last_meal_start;
	pthread_mutex_unlock(&table->mute_last_meal[i]);
	if (millisec >= table->philos[i].rules->time_to_die)
	{
		send_message(&table->philos[i], 5);
		pthread_mutex_lock(table->mute_alive);
		*table->everybody_lives = 0;
		pthread_mutex_unlock(table->mute_alive);
	}
}

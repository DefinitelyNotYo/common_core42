/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:51:42 by yoherfan          #+#    #+#             */
/*   Updated: 2025/07/04 18:21:40 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void	actions(t_philosofer *philo)
{
	while (1)
	{
		pthread_mutex_lock(philo->mute_alive);
		if (*philo->everybody_lives == 0)
			return (pthread_mutex_unlock(philo->mute_alive), (void)0);
		pthread_mutex_unlock(philo->mute_alive);
		lock_fork(philo);
		send_message(philo, 1);
		send_message(philo, 1);
		send_message(philo, 2);
		ft_eat(philo);
		unlock_fork(philo);
		pthread_mutex_lock(philo->mute_max_meals);
		if (philo->meals == philo->rules->notepme)
			return (pthread_mutex_unlock(philo->mute_max_meals), (void)0);
		pthread_mutex_unlock(philo->mute_max_meals);
		send_message(philo, 3);
		ft_sleep(philo);
		send_message(philo, 4);
		ft_think(philo);
	}
}

void	monitor(t_table *table)
{
	int	i;

	while (*table->everybody_lives == 1)
	{
		i = -1;
		while (++i < table->n_philos)
		{
			pthread_mutex_lock(table->philos[i].mute_max_meals);
			if (table->philos[i].meals == table->philos[i].rules->notepme)
			{
				pthread_mutex_unlock(table->philos[i].mute_max_meals);
				continue ;
			}
			pthread_mutex_unlock(table->philos[i].mute_max_meals);
			death_bell_lock(table, i);
		}
		if (check_meals(table) == 1)
			return ;
	}
}

// while (get_time_stamp() - philo->last_meal_start \
// <= philo->rules->time_to_eat)
// 	;
void	ft_eat(t_philosofer *philo)
{
	pthread_mutex_lock(philo->mute_alive);
	if (*philo->everybody_lives == 0)
		return (pthread_mutex_unlock(philo->mute_alive), (void)0);
	pthread_mutex_unlock(philo->mute_alive);
	pthread_mutex_lock(philo->mute_last_meal);
	philo->last_meal_start = get_time_stamp();
	pthread_mutex_unlock(philo->mute_last_meal);
	usleep(philo->rules->time_to_eat * 1000);
	pthread_mutex_lock(philo->mute_max_meals);
	philo->meals += 1;
	pthread_mutex_unlock(philo->mute_max_meals);
}

void	ft_sleep(t_philosofer *philo)
{
	pthread_mutex_lock(philo->mute_alive);
	if (*philo->everybody_lives == 0)
		return (pthread_mutex_unlock(philo->mute_alive), (void)0);
	pthread_mutex_unlock(philo->mute_alive);
	usleep(philo->rules->time_to_sleep * 1000);
}

void	ft_think(t_philosofer *philo)
{
	pthread_mutex_lock(philo->mute_alive);
	if (*philo->everybody_lives == 0)
		return (pthread_mutex_unlock(philo->mute_alive), (void)0);
	pthread_mutex_unlock(philo->mute_alive);
	usleep(100);
}

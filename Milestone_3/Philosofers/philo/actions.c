/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:51:42 by yoherfan          #+#    #+#             */
/*   Updated: 2025/07/03 17:30:28 by yoherfan         ###   ########.fr       */
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
		if (philo->id == 1)
		{
			pthread_mutex_lock(philo->fork_dx);
			pthread_mutex_lock(philo->fork_sx);
		}
		else
		{
			pthread_mutex_lock(philo->fork_sx);
			pthread_mutex_lock(philo->fork_dx);
		}
		send_message(philo, 1); //philo has taken a fork
		send_message(philo, 1); //philo has taken a fork
		send_message(philo, 2);
		ft_eat(philo);
		if (philo->id == 1)
		{
			pthread_mutex_unlock(philo->fork_sx);
			pthread_mutex_unlock(philo->fork_dx);
		}
		else
		{
			pthread_mutex_unlock(philo->fork_dx);
			pthread_mutex_unlock(philo->fork_sx);
		}
		pthread_mutex_lock(philo->mute_max_meals);
		if (philo->meals == philo->rules->number_of_times_each_philosopher_must_eat)
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
	int i;
	long long millisec;
	
	while(*table->everybody_lives == 1)
	{
		i = -1;
		while (++i < table->n_philos)
		{
			pthread_mutex_lock(table->philosofers[i].mute_max_meals);
			if (table->philosofers[i].meals == table->philosofers[i].rules->number_of_times_each_philosopher_must_eat)
			{
				pthread_mutex_unlock(table->philosofers[i].mute_max_meals);
				continue;
			}
			pthread_mutex_unlock(table->philosofers[i].mute_max_meals);
			pthread_mutex_lock(&table->mute_last_meal[i]);
			millisec = get_time_stamp() - table->philosofers[i].last_meal_start;
			pthread_mutex_unlock(&table->mute_last_meal[i]);
			if (millisec >= table->philosofers[i].rules->time_to_die)
			{
				send_message(&table->philosofers[i], 5);
				pthread_mutex_lock(table->mute_alive);
				*table->everybody_lives = 0;
				pthread_mutex_unlock(table->mute_alive);
			}
		}
		if (check_meals(table) == 1)
			return ;
	}
	usleep(50);
}

void	ft_eat(t_philosofer *philo)
{
	pthread_mutex_lock(philo->mute_alive);
		if (*philo->everybody_lives == 0)
			return (pthread_mutex_unlock(philo->mute_alive), (void)0);
	pthread_mutex_unlock(philo->mute_alive);
	pthread_mutex_lock(philo->mute_last_meal);
	philo->last_meal_start = get_time_stamp();
	pthread_mutex_unlock(philo->mute_last_meal);
	while (get_time_stamp() - philo->last_meal_start <= philo->rules->time_to_eat)
		;
	pthread_mutex_lock(philo->mute_max_meals);
	philo->meals += 1;
	pthread_mutex_unlock(philo->mute_max_meals);
}

void    ft_sleep(t_philosofer *philo)
{
	pthread_mutex_lock(philo->mute_alive);
	if (*philo->everybody_lives == 0)
		return (pthread_mutex_unlock(philo->mute_alive), (void)0);
	pthread_mutex_unlock(philo->mute_alive);
	while (get_time_stamp() - philo->last_meal_start <= philo->rules->time_to_sleep + philo->rules->time_to_eat)
		;
}

void	ft_think(t_philosofer *philo)
{
	pthread_mutex_lock(philo->mute_alive);
	if (*philo->everybody_lives == 0)
		return (pthread_mutex_unlock(philo->mute_alive), (void)0);
	pthread_mutex_unlock(philo->mute_alive);
	usleep(50);
}

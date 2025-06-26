/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 16:51:42 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/26 17:22:17 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void	actions(t_philosofer *philo)
{
	while (philo->run == 1)
	{
		pthread_mutex_lock(philo->fork_dx);
		send_message(philo, 1); //philo has taken a fork
		pthread_mutex_lock(philo->fork_sx);
		send_message(philo, 1); //philo has taken a fork
		ft_eat(philo);
		pthread_mutex_unlock(philo->fork_dx);
		pthread_mutex_unlock(philo->fork_sx);
		ft_sleep(philo);
		ft_think(philo);
	}
	printf("sono uscito da filosofo %d\n", philo->id);
}

void	monitor(t_table *table)
{
	int i;
	
	while(table->everybody_lives == 1)
	{
		i = -1;
		while (++i < table->n_philos)
		{
			if (get_time_stamp() - table->clock - table->philosofers[i].last_meal_start >= table->philosofers[i].rules->time_to_die)
			{
				table->everybody_lives = 0;
				send_message(&table->philosofers[i], 5);
				i = -1;
				while (++i < table->n_philos)
					table->philosofers[i].run = 0;
			}
		}
	}
	usleep(50);
	printf("sono uscito dalla morte\n");
}

void	ft_eat(t_philosofer *philo)
{
	pthread_mutex_lock(&philo->mute_last_meal);
	philo->last_meal_start = get_time_stamp();
	pthread_mutex_unlock(&philo->mute_last_meal);
	send_message(philo, 2);
	while (get_time_stamp() - *philo->clock - philo->last_meal_start <= philo->rules->time_to_eat)
		;
}

void    ft_sleep(t_philosofer *philo)
{
	send_message(philo, 3);
	while (get_time_stamp() - *philo->clock - philo->last_meal_start <= philo->rules->time_to_sleep)
		;
}

void	ft_think(t_philosofer *philo)
{
	send_message(philo, 4);
	usleep(50);
}

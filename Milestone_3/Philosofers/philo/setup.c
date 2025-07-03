/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:12:11 by yoherfan          #+#    #+#             */
/*   Updated: 2025/07/03 17:29:23 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void	setup_table(t_table *table, t_rules *rules, int argc, char **argv)
{
	table->clock = get_time_stamp();
	table->everybody_lives = safe_malloc(sizeof(int));
	*table->everybody_lives = 1;
	table->n_philos = ft_atoll(argv[1]);
	rules->time_to_die = ft_atoll(argv[2]);
	rules->time_to_eat = ft_atoll(argv[3]);
	rules->time_to_sleep = ft_atoll(argv[4]);
	if (argc == 6)
		rules->number_of_times_each_philosopher_must_eat = ft_atoll(argv[5]);
	else
		rules->number_of_times_each_philosopher_must_eat = -1;
	table->philosofers = safe_malloc(sizeof(t_philosofer) * table->n_philos);
	table->threads = safe_malloc(sizeof(pthread_t) * table->n_philos);
	table->forks = safe_malloc(sizeof(pthread_mutex_t) * table->n_philos);
	table->mute_alive = safe_malloc(sizeof(pthread_mutex_t));
	table->mute_last_meal = safe_malloc(sizeof(pthread_mutex_t) * table->n_philos);
	table->mute_max_meals = safe_malloc(sizeof(pthread_mutex_t) * table->n_philos);
	table->death = safe_malloc(sizeof(pthread_t) * 1);
	setup_threads(table, rules);
}

void	setup_threads(t_table *table, t_rules *rules)
{
	int	i;
	
	init_mutex(table);
	set_philosofers(table, rules);
	if (table->n_philos == 1)
		pthread_create(&table->threads[0], NULL, (void *)&actions_one, &table->philosofers[0]);
	else
	{
		i = -1;
		while (++i < table->n_philos)
			if (i % 2 == 1)
				pthread_create(&table->threads[i], NULL, (void *)&actions, &table->philosofers[i]);
		i = -1;
		usleep(100);
		while (++i < table->n_philos)
			if (i % 2 == 0)
				pthread_create(&table->threads[i], NULL, (void *)&actions, &table->philosofers[i]);
	}
	pthread_create(table->death, NULL, (void *)&monitor, table);
	i = -1;
	while (++i < table->n_philos)
		pthread_join(table->threads[i], NULL);
	pthread_join(*table->death, NULL);
}

void	set_philosofers(t_table *table, t_rules *rules)
{
	int	i;
	i = -1;
	while (++i < table->n_philos)
	{
		table->philosofers[i].clock = table->clock;
		table->philosofers[i].last_meal_start = table->clock;
		table->philosofers[i].meals = 0;
		table->philosofers[i].rules = rules;
		table->philosofers[i].id = i + 1;
		table->philosofers[i].everybody_lives = &(*table->everybody_lives);
		table->philosofers[i].fork_dx = &table->forks[i];
		if (table->n_philos != 1)
		{
			if(i == 0)
				table->philosofers[i].fork_sx = &table->forks[table->n_philos - 1];
			else
				table->philosofers[i].fork_sx = &table->forks[i - 1];			
		}
		table->philosofers[i].mute_alive = table->mute_alive;
		table->philosofers[i].mute_last_meal = &table->mute_last_meal[i];
		table->philosofers[i].mute_max_meals = &table->mute_max_meals[i];
	}
}

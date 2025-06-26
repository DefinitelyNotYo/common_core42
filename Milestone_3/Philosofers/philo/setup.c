/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 15:12:11 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/26 17:18:57 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void	setup_table(t_table *table, t_rules *rules, int argc, char **argv)
{
	table->clock = get_time_stamp();
	table->everybody_lives = 1;
	table->n_philos = ft_atoll(argv[1]);
	rules->time_to_die = ft_atoll(argv[2]);
	rules->time_to_eat = ft_atoll(argv[3]);
	rules->time_to_sleep = ft_atoll(argv[4]);
	if (argc == 6)
		rules->number_of_times_each_philosopher_must_eat = ft_atoll(argv[5]);
	table->philosofers = safe_malloc(sizeof(t_philosofer) * table->n_philos);
	table->threads = safe_malloc(sizeof(pthread_t) * table->n_philos);
	table->forks = safe_malloc(sizeof(pthread_mutex_t) * table->n_philos);
	table->death = safe_malloc(sizeof(pthread_t) * 1);
	setup_threads(table, rules);
}

void	setup_threads(t_table *table, t_rules *rules)
{
	int	i;
	i = -1;
	while (++i < table->n_philos)
		pthread_mutex_init(&table->forks[i], NULL);
	set_philosofers(table, rules);
	i = -1;
	while (++i < table->n_philos)
		if (i % 2 == 0)
			pthread_create(&table->threads[i], NULL, (void *)&actions, &table->philosofers[i]);
	usleep(50);
	i = -1;
	while (++i < table->n_philos)
		if (i % 2 == 1)
			pthread_create(&table->threads[i], NULL, (void *)&actions, &table->philosofers[i]);
	usleep(50);
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
		table->philosofers[i].clock = &table->clock;
		table->philosofers[i].rules = rules;
		table->philosofers[i].id = i + 1;
		table->philosofers[i].run = 1;
		table->philosofers[i].fork_dx = &table->forks[i];
		if(i == 0)
			table->philosofers[i].fork_sx = &table->forks[table->n_philos - 1];
		else
			table->philosofers[i].fork_sx = &table->forks[i - 1];
	}
}

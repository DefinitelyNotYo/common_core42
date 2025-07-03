/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/01 16:24:09 by yoherfan          #+#    #+#             */
/*   Updated: 2025/07/03 17:52:25 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void	init_mutex(t_table *table)
{
	int	i;

	i = -1;
	pthread_mutex_init(table->mute_alive, NULL);
	while (++i < table->n_philos)
	{
		pthread_mutex_init(&table->forks[i], NULL);
		pthread_mutex_init(&table->mute_last_meal[i], NULL);
		pthread_mutex_init(&table->mute_max_meals[i], NULL);
		table->philosofers[i].mute_alive = table->mute_alive;
	}	
}

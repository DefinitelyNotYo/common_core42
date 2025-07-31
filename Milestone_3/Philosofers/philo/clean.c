/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/26 16:45:46 by yoherfan          #+#    #+#             */
/*   Updated: 2025/07/04 14:57:27 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

void	clean_memory(t_table *table)
{
	pthread_mutex_destroy(table->forks);
	pthread_mutex_destroy(table->mute_alive);
	pthread_mutex_destroy(table->mute_last_meal);
	pthread_mutex_destroy(table->mute_max_meals);
	free (table->everybody_lives);
	free (table->philos);
	free (table->threads);
	free (table->forks);
	free (table->mute_alive);
	free (table->mute_last_meal);
	free (table->mute_max_meals);
	free (table->death);
}

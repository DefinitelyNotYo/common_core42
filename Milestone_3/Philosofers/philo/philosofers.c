/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:36:26 by yoherfan          #+#    #+#             */
/*   Updated: 2025/07/03 17:46:40 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosofers.h"

int	main(int argc, char **argv)
{
	t_table	table;
	t_rules rules;
	if (parse_inputs(argc, argv) == -1)
		return (0);
	setup_table(&table, &rules, argc, argv);
	clean_memory(&table);
}

	// (void)argc;
	// (void)argv;
	// struct timeval time;
	// gettimeofday(&time, NULL);
	// printf("secondi: %ld\nmicrosecondi: %ld\n", time.tv_sec, time.tv_usec);
	// pthread_t *t;
	// n = 0;
	// // t = malloc(sizeof(pthread_t) * 100);
	// t = malloc(sizeof(pthread_t) * 5);
	// int i = -1;
	// while (++i < 5)
	// 	pthread_create(&t[i], NULL, &routine, NULL);
	// i = -1;
	// while (++i < 5)
	// 	pthread_join(t[i], NULL);
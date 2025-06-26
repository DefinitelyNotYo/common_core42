/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoherfan <yoherfan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 14:36:28 by yoherfan          #+#    #+#             */
/*   Updated: 2025/06/26 17:19:10 by yoherfan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOFERS_H
# define PHILOSOFERS_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include <ctype.h>
# include <fcntl.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <linux/limits.h>
# include <errno.h>
# include <signal.h>
# include <termios.h>
#include <sys/time.h>
#include <pthread.h>

typedef struct s_rules
{
	long long 		time_to_die;
	long long 		time_to_eat;
	long long 		time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
}	t_rules;

typedef struct s_philosofer
{
	int	id;
	pthread_mutex_t	*fork_dx;
	pthread_mutex_t	*fork_sx;
	pthread_mutex_t	mute_last_meal;
	long long		last_meal_start;
	int				run;
	long long		*clock;
	t_rules			*rules;
}	t_philosofer;

typedef struct s_table
{
	int 			n_philos;
	long long		clock;
	t_philosofer 	*philosofers;
	pthread_t		*threads;
	pthread_mutex_t *forks;
	pthread_t		*death;
	int				everybody_lives;
}	t_table;

//ACTIONS.C
void		actions(t_philosofer *philo);
void		monitor(t_table *table);
void		ft_eat(t_philosofer *philo);
void		ft_sleep(t_philosofer *philo);
void		ft_think(t_philosofer *philo);
//MESSAGES.C
void		send_message(t_philosofer *philo, int flag);
//PARSING.C
int			parse_inputs(int argc, char **argv);
int			contains_not_numbers(char *str);
//PHILOSOFERS.C

//SETUP.C
void		setup_table(t_table *table, t_rules *rules, int argc, char **argv);
void		setup_threads(t_table *table, t_rules *rules);
void		set_philosofers(t_table *table, t_rules *rules);
//UTILS.C
void		ft_putnbr(long long n, int fd);
long long	ft_atoll(char *nptr);
long long	get_time_stamp();
//WRAP.C
void		*safe_malloc(size_t size);

#endif
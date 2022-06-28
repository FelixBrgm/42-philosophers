/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:43:54 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/28 14:49:52 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_data
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_times_each_philosopher_must_eat;
	long			timestamp_init;
	pthread_mutex_t	*died;
	pthread_mutex_t	*log;
}				t_data;

typedef struct s_philosopher
{
	int				id;
	int				times_eaten;
	long			dead;
	long			last_time_eaten;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	t_data			*data;
}				t_philosopher;

// Input
int				input_parse(t_data *data, int argc, char **argv);

// Philo_init
void			philo_init(t_philosopher **philosophers, pthread_t *threads);
void			threads_detach(pthread_t *threads, t_data *data);

// Philo_create
t_philosopher	**philo_create(t_data *data, pthread_mutex_t *forks);

// Philo_runtime
int				philo_runtime(t_philosopher *p);

// mutex_utils
int				mutex_init(pthread_mutex_t *mutex, int n);

// Philo_checker
void			philo_checker(t_philosopher **philos);

// utils
int				ft_atoi(const char *str);
long			ft_atoi_l(const char *str);
int				is_space(char c);

// log
void			log_fork(pthread_mutex_t mutex, long timestamp_init, int id);
void			log_eating(pthread_mutex_t mutex, long timestamp_init, int id);
void			log_sleeping(pthread_mutex_t mutex,
					long timestamp_init, int id);
void			log_thinking(pthread_mutex_t mutex,
					long timestamp_init, int id);
void			log_died(pthread_mutex_t mutex, long timestamp_init, int id);

// Time
long			get_current_time_ms(void);
void			sleep_ms(int ms);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:43:54 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/24 13:41:35 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

typedef struct s_philosopher
{
	int	id;
	int	number_of_philosophers;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	number_of_times_each_philosopher_must_eat;
	long	timestamp_init;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	pthread_mutex_t	*died;
	pthread_mutex_t	log;
}				t_philosopher;

// Start
int philosopher_start(t_philosopher *philosoper);

// Utils
int	threads_init(pthread_mutex_t *mutex, int n);


// Time
long	get_current_time_ms(void);
void	sleep_ms(int ms);

// Log
void	log_fork(pthread_mutex_t mutex, long timestamp_init, int id);
void	log_eating(pthread_mutex_t mutex, long timestamp_init, int id);
void	log_sleeping(pthread_mutex_t mutex, long timestamp_init, int id);
void	log_thinking(pthread_mutex_t mutex, long timestamp_init, int id);
void	log_died(pthread_mutex_t mutex, long timestamp_init, int id);

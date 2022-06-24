/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_start.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:21:58 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/24 15:39:55 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void forks_take(pthread_mutex_t *fork_left, pthread_mutex_t *fork_right);
void forks_leave(pthread_mutex_t *fork_left, pthread_mutex_t *fork_right);
void check_if_dead(long last_time_eaten, t_philosopher *p);

int philosopher_start(t_philosopher *p)
{
	long last_time_eaten = p->timestamp_init;
	if (!p)
		return(1);

	if (p->id % 2 == 1)
		sleep_ms(5);
	while(pthread_mutex_lock(p->died) != 0)
	{
		check_if_dead(last_time_eaten, p);
		if (pthread_mutex_lock(p->died) == 0)
			break;
		forks_take(p->fork_left, p->fork_right);
		log_eating(p->log, p->timestamp_init, p->id);
		sleep_ms(p->time_to_eat);
		check_if_dead(last_time_eaten, p);
		if (pthread_mutex_lock(p->died) == 0)
			break;
		last_time_eaten = get_current_time_ms();
		forks_leave(p->fork_left, p->fork_right);
		check_if_dead(last_time_eaten, p);
		if (pthread_mutex_lock(p->died) == 0)
			break;
		log_sleeping(p->log, p->timestamp_init, p->id);
		sleep_ms(p->time_to_sleep);
		check_if_dead(last_time_eaten, p);
		if (pthread_mutex_lock(p->died) == 0)
			break;
		log_thinking(p->log, p->timestamp_init, p->id);
	}
	pthread_mutex_unlock(p->died);
	return (0);
}

void check_if_dead(long last_time_eaten, t_philosopher *p)
{
	if (get_current_time_ms() - last_time_eaten > p->time_to_die)
	{
		pthread_mutex_init(p->died, NULL);
		log_died(p->log, p->timestamp_init, p->id);
	}
}

void forks_take(pthread_mutex_t *fork_left, pthread_mutex_t *fork_right)
{
	pthread_mutex_lock(fork_left);
	pthread_mutex_lock(fork_right);
}

void forks_leave(pthread_mutex_t *fork_left, pthread_mutex_t *fork_right)
{
	pthread_mutex_unlock(fork_left);
	pthread_mutex_unlock(fork_right);
}
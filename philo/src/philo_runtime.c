/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_runtime.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 15:11:52 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/26 18:35:32 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void check_if_dead(t_philosopher *p);
void forks_take(t_philosopher *p);
void forks_leave(t_philosopher *p);
int	has_eaten_enough(t_philosopher *p);

int philo_runtime(t_philosopher *p)
{
	if (!p)
		return (1);
	if (p->id == 0)
		p->data->timestamp_init = get_current_time_ms();
	p->last_time_eaten = get_current_time_ms();
	if (p->id % 2 == 1)
		sleep_ms(5);

	while(has_eaten_enough(p) == 0)
	{
		forks_take(p);
		log_eating(*(p->data->log), p->data->timestamp_init,p->id);
		sleep_ms(p->data->time_to_eat);
		forks_leave(p);
		
		p->last_time_eaten = get_current_time_ms();
		log_sleeping(*(p->data->log), p->data->timestamp_init,p->id);
		sleep_ms(p->data->time_to_sleep);
		log_thinking(*(p->data->log), p->data->timestamp_init,p->id);
		p->times_eaten++;
	}
	return (0);
}

int	has_eaten_enough(t_philosopher *p)
{
	int	times_must_eat;
	
	times_must_eat = p->data->number_of_times_each_philosopher_must_eat;
	if (times_must_eat == -1 || times_must_eat > p->times_eaten)
		return (0);
	return (1);
}

void forks_take(t_philosopher *p)
{
	pthread_mutex_lock(p->fork_left);
	log_fork(*(p->data->log), p->data->timestamp_init, p->id);
	pthread_mutex_lock(p->fork_right);
	log_fork(*(p->data->log), p->data->timestamp_init, p->id);
}

void forks_leave(t_philosopher *p)
{
	pthread_mutex_unlock(p->fork_left);
	pthread_mutex_unlock(p->fork_right);
}



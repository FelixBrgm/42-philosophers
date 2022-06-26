/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:34:33 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/26 17:07:44 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	log_fork(pthread_mutex_t mutex, long timestamp_init, int id)
{
	if(pthread_mutex_lock(&mutex) == 0)
	{
		printf("%ld %i has taken a fork\n", get_current_time_ms() - timestamp_init, id);
		pthread_mutex_unlock(&mutex);
	}
}

void	log_eating(pthread_mutex_t mutex, long timestamp_init, int id)
{
	if(pthread_mutex_lock(&mutex) == 0)
	{
		printf("%ld %i is eating\n", get_current_time_ms() - timestamp_init, id);
		pthread_mutex_unlock(&mutex);
	}
}

void	log_sleeping(pthread_mutex_t mutex, long timestamp_init, int id)
{
	if(pthread_mutex_lock(&mutex) == 0)
	{
		printf("%ld %i is sleeping\n", get_current_time_ms() - timestamp_init, id);
		pthread_mutex_unlock(&mutex);
	}
}

void	log_thinking(pthread_mutex_t mutex, long timestamp_init, int id)
{
	if(pthread_mutex_lock(&mutex) == 0)
	{
		printf("%ld %i is thinking\n", get_current_time_ms() - timestamp_init, id);
		pthread_mutex_unlock(&mutex);
	}
}
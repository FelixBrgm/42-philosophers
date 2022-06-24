/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:40:58 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/24 16:13:48 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main()
{
	int i;
	int	number_of_philosophers = 3;
	pthread_mutex_t mutex[number_of_philosophers];
	pthread_mutex_t died;
    pthread_t threads[number_of_philosophers];
	t_philosopher	*philosopher;
	long timestamp_since_init;

	i = 0;
	// Initialisation of the mutexes
	threads_init(mutex, number_of_philosophers);
	i = 0;
	while (i < number_of_philosophers)
	{
		if (i == 0)
			timestamp_since_init = get_current_time_ms();
		philosopher = malloc(sizeof(t_philosopher));
		philosopher->number_of_philosophers = number_of_philosophers;
        philosopher->id = i;
        philosopher->time_to_die = 0;
        philosopher->time_to_eat = 500;
        philosopher->time_to_sleep = 500;
		philosopher->died = &died;
		philosopher->timestamp_init = timestamp_since_init;

		// FORK ASINGMENT
		if (philosopher->id == 0)
			philosopher->fork_left = &mutex[philosopher->number_of_philosophers -1];
		else
			philosopher->fork_left = &mutex[philosopher->id -1];
		philosopher->fork_right = &mutex[philosopher->id];
		
		pthread_mutex_init(&(philosopher->log), NULL);
		pthread_create(&threads[i], NULL, (void * _Nullable (* _Nonnull)(void * _Nullable)) philosopher_start,philosopher);
		i++;
	}
	i = 0;
    while (i < number_of_philosophers)
        pthread_join(threads[i++], NULL);
	return (0);
}
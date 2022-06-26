/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:33:17 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/26 17:21:16 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data			data;
	pthread_mutex_t	mutex[250];
	pthread_mutex_t	log;
	pthread_mutex_t	died;
	pthread_t		threads[251];
	t_philosopher	**philosophers;
	int				i;

	if(input_parse(&data, argc, argv))
	{
		printf("Error\nWrong arguments\n");
		return (1);
	}
	mutex_init(mutex, data.number_of_philosophers);
	pthread_mutex_init(&log, NULL);
	data.log = &log;
	data.died = &died;
	philosophers = philo_create(&data, mutex);
	philo_init(philosophers, threads);

	while (pthread_mutex_lock(&died));
	
	threads_detach(threads, &data);
	sleep_ms(2);
	i = 0;
	while(philosophers[i])
	{
		if (philosophers[i]->dead)
		{
			printf("%ld %i died\n", philosophers[i]->dead, i);
			return (0);
		}
		i++;
	}
	return (0);
}
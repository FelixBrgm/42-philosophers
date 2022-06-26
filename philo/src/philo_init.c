/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:33:50 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/26 17:30:25 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

void	philo_init(t_philosopher **philosophers, pthread_t *threads)
{
	int	i;

	i = 0;
	while (philosophers[i])
	{
		pthread_create(&threads[i], NULL , (void * _Nullable (* _Nonnull)(void * _Nullable)) philo_runtime, philosophers[i]);
		i++;
	}
	pthread_create(&threads[250], NULL, (void * _Nullable (* _Nonnull)(void * _Nullable)) philo_checker, philosophers);
}

void threads_detach(pthread_t *threads, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->number_of_philosophers)
	{
		pthread_detach(threads[i]);
		i++;
	}
	pthread_detach(threads[250]);
}
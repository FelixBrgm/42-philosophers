/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 14:02:39 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/26 18:39:15 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

t_philosopher	**philo_create(t_data *data, pthread_mutex_t *forks)
{
	int				i;
	t_philosopher	**philosophers;

	i = 0;
	philosophers = malloc (sizeof(t_philosopher *)
			* data->number_of_philosophers + 1);
	philosophers[data->number_of_philosophers] = NULL;
	while (i < data->number_of_philosophers)
	{
		philosophers[i] = malloc(sizeof(t_philosopher));
		philosophers[i]->data = data;
		philosophers[i]->dead = 0;
		philosophers[i]->id = i;
		philosophers[i]->times_eaten = 0;
		if (i == 0)
			philosophers[i]->fork_left
				= &forks[philosophers[i]->data->number_of_philosophers -1];
		else
			philosophers[i]->fork_left = &forks[i -1];
		philosophers[i]->fork_right = &forks[i];
		i++;
	}
	return (philosophers);
}

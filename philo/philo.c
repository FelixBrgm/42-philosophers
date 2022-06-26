/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:33:17 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/26 18:49:15 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	log_death(t_philosopher **philosophers);

typedef struct s_vars
{
	pthread_mutex_t	mutex[250];
	pthread_mutex_t	log;
	pthread_mutex_t	died;
	pthread_t		threads[251];
}				t_vars;

int	main(int argc, char **argv)
{
	t_data			data;
	t_vars			vars;
	t_philosopher	**philosophers;
	int				i;

	if (input_parse(&data, argc, argv))
	{
		printf("Error\nWrong arguments\n");
		return (1);
	}
	mutex_init(vars.mutex, data.number_of_philosophers);
	pthread_mutex_init(&(vars.log), NULL);
	data.log = &(vars.log);
	data.died = &(vars.died);
	philosophers = philo_create(&data, vars.mutex);
	philo_init(philosophers, vars.threads);
	while (pthread_mutex_lock(&(vars.died)))
		printf("");
	threads_detach(vars.threads, &data);
	sleep_ms(2);
	i = 0;
	log_death(philosophers);
	return (0);
}

void	log_death(t_philosopher **philosophers)
{
	int	i;

	i = 0;
	while (philosophers[i])
	{
		if (philosophers[i]->dead)
		{
			printf("%ld %i died\n", philosophers[i]->dead, i + 1);
			exit (0);
		}
		i++;
	}
}

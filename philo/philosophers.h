/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 23:43:54 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/25 15:16:34 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

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
	int				dead;
	pthread_mutex_t	*fork_left;
	pthread_mutex_t	*fork_right;
	t_data			data;
}				t_philosopher;

// Input
int	input_parse(t_data *data, int argc, char **argv);

// Philo_start

// mutex_utils

// threads_utils

// utils
int		ft_atoi(const char *str);
long	ft_atoi_l(const char *str);
int		is_space(char c);

// log

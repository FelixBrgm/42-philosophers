/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:33:33 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/26 18:50:46 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"
#include <limits.h>

int	ft_strlen(char *str);
int	input_check(int argc, char **argv);

int	input_parse(t_data *data, int argc, char **argv)
{
	if (input_check(argc, argv))
		return (1);
	data->number_of_philosophers = ft_atoi(argv[1]);
	if (data->number_of_philosophers > 250)
		return (1);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		data->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
	else
		data->number_of_times_each_philosopher_must_eat = -1;
	return (0);
}

int	input_check(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 5 || argc > 6)
		return (1);
	i = 1;
	while (argv[i])
	{
		if (ft_atoi_l(argv[i]) > 2147483647 || ft_atoi_l(argv[i]) < -2147483648)
			return (1);
		if (ft_atoi(argv[i]) != ft_atoi_l(argv[i]))
			return (1);
		j = 0;
		while (argv[i][j])
		{
			if (0 == is_space(argv[i][j]) && (argv[i][j] > '9'
			|| argv[i][j] < '0' ))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
		i++;
	return (i);
}

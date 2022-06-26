/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:33:17 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/25 15:09:07 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int argc, char **argv)
{
	t_data data;

	if(input_parse(&data, argc, argv))
	{
		printf("Error\nWrong arguments\n");
		return (1);
	}
	
}
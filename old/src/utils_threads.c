/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 11:39:28 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/24 11:43:48 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	threads_init(pthread_mutex_t *mutex, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		pthread_mutex_init(&mutex[i], NULL);
		i++;
	}
	return (0);
}
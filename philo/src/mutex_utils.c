/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 14:34:06 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/26 13:58:45 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

int	mutex_init(pthread_mutex_t *mutex, int n)
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
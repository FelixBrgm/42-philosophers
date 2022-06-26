/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 13:11:11 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/24 13:41:28 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philosophers.h"

long	get_current_time_ms(void)
{
	struct timeval current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec *1000 + current_time.tv_usec/1000);
}

void	sleep_ms(int ms)
{
	usleep(ms * 1000);
}
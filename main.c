/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 22:37:12 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/23 17:24:00 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>

#ifndef NUM_THREADS
#define NUM_THREADS 4
#endif

typedef struct s_vars
{
    int id;
    int count_philosopers;
    int time_to_eat;
    int time_to_sleep;
    int time_to_die;
    long last_time_eaten;
}               t_vars;


pthread_mutex_t mutex[NUM_THREADS];
pthread_mutex_t died;

void *philosopher_start(void* param)
{

	t_vars *vars =(t_vars *) param;

    while(pthread_mutex_lock(&died) != 0)
    {
        printf("Hello from ID: %i\n", vars->id);
    }
    pthread_mutex_unlock(&died);
    printf("DIED: %i\n", vars->id);
    return (0);
}

int main()
{
    // struct timeval *time;
    // printf("TIME: %i\n", gettimeofday(time, NULL));
    // printf("TIME: %li\n", time->tv_sec);
    pthread_t threads[NUM_THREADS];
    int i;
    t_vars *vars;
    while (i < NUM_THREADS)
		pthread_mutex_init(&mutex[i++], NULL);
    i = 0;
    while (i < NUM_THREADS)
    {
        vars = malloc(sizeof(t_vars));
        vars->count_philosopers = NUM_THREADS;
        vars->id = i;
        vars->time_to_die = 2000;
        vars->time_to_eat = 500;
        vars->time_to_sleep = 500;
        pthread_create(&threads[i], NULL, philosopher_start,NULL);
        i++;
    }
    i = 0;
    while (i < NUM_THREADS)
        pthread_join(threads[i++], NULL);

    exit(EXIT_SUCCESS);
}
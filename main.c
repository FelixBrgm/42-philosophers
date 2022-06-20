/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 22:37:12 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/20 15:54:44 by fbruggem         ###   ########.fr       */
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
        struct timeval *temp;
    
    while(pthread_mutex_lock(&died) != 0)
    {
        usleep(5000);
        if (vars->id % 2 == 1)
            usleep(1000000);
        if (vars->count_philosopers == vars->id + 1)
            pthread_mutex_lock(&mutex[0]);
        else
            pthread_mutex_lock(&mutex[vars->id]);
        if (vars->id == 0)
            pthread_mutex_lock(&mutex[vars->count_philosopers -1]);
        else
            pthread_mutex_lock(&mutex[vars->id -1]);
            printf("HELLO");
        gettimeofday(temp, NULL);
        if (temp->tv_sec - vars->last_time_eaten > vars->time_to_die)
        	pthread_mutex_init(&died, NULL);
        usleep(vars->time_to_eat * 1000);
        printf("%i ate with left time %li\n", vars->id, temp->tv_sec - vars->last_time_eaten);
        vars->last_time_eaten = temp->tv_sec;

        
        if (vars->count_philosopers == vars->id + 1)
            pthread_mutex_unlock(&mutex[0]);
        else
            pthread_mutex_unlock(&mutex[vars->id]);
        if (vars->id == 0)
            pthread_mutex_unlock(&mutex[vars->count_philosopers -1]);
        else
            pthread_mutex_unlock(&mutex[vars->id -1]);
        
        usleep(vars->time_to_sleep* 1000);
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
    
    t_vars *vars;
    for (int i = 0; i < NUM_THREADS; ++i)
		pthread_mutex_init(&mutex[i], NULL);

    for (int i = 0; i < NUM_THREADS; ++i) {
        vars = malloc(sizeof(t_vars));
        vars->count_philosopers = NUM_THREADS;
        vars->id = i;
        vars->time_to_die = 2000;
        vars->time_to_eat = 500;
        vars->time_to_sleep = 500;
        pthread_create(&threads[i], NULL, philosopher_start,(void *) vars);
    }
    
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    exit(EXIT_SUCCESS);
}
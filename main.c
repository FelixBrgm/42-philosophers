/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbruggem <fbruggem@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 22:37:12 by fbruggem          #+#    #+#             */
/*   Updated: 2022/06/14 23:39:05 by fbruggem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>

#ifndef NUM_THREADS
#define NUM_THREADS 4
#endif

pthread_mutex_t mutex[NUM_THREADS];

void *func3(void* param)
{
    pthread_mutex_lock(&mutex);
	int *i =(int *) param;
	
    pthread_mutex_unlock(&mutex);
    return 0;
}

int main()
{
    pthread_t threads[NUM_THREADS];
	int i = 0;
	while (i < NUM_THREADS)
		mutex[i] = PTHREAD_MUTEX_INITIALIZER;
	
    for (int i = 0; i < NUM_THREADS; ++i) {
		int *x = malloc(sizeof(int) * 2);
		x[0] = i;
        pthread_create(&threads[i], NULL, func3,(void *) x);
    }

    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    printf("%d\n", shared);
    exit(EXIT_SUCCESS);
}
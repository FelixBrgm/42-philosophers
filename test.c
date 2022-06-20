
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/time.h>



int main () 
{
    struct timeval *time = malloc(sizeof(struct timeval));
	gettimeofday(time, NULL);
    printf("TIME: %li%i\n", time->tv_sec, time->tv_usec);
	sleep(2);
	gettimeofday(time, NULL);
    printf("TIME: %li%i\n", time->tv_sec, time->tv_usec);

}	
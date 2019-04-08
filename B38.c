#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <stdlib.h>

int i = 0;	
int amt = 0;
int total = 0;

void *count(void *X)
{
	for (i=0; i < amt; i++)
	{
        double X = (double)rand() / RAND_MAX;
        double Y = (double)rand() / RAND_MAX;
        
        if (((X * X) + (Y * Y)) <= 1)
        	{
	 		total++;
        	}
    	}
	return NULL;
}


int main()
{
    printf("\n\nCalculating value of Pi, using Monte Carlo\n\n");
    srand(time(NULL));
    pthread_t thread;

	do
	{
        printf("Please enter a positive number of points you would like to generate? \n");
        scanf("%d", &amt);  	
	}
	while (amt <= 0);

    pthread_create(&thread, NULL, &count, NULL);
    pthread_join(thread, NULL);
    
    double points = 4.0 * total;
    double pi = points / amt;
    printf("The approximate value of Pi for the desired amount of points (%d) is: %f \n", amt, pi);  
    return 0;
}
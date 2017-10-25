#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
 
pthread_t tid1;
pthread_t tid2;
int status;
int status_l,status_k;

 
void* Lohan(void *arg)
{
	status=0;
	status_l=100;
	while(status_l>0)
	{
		sleep(10);
		status_l-=10;
	}
	status=1;printf("Game Over\n");exit(EXIT_SUCCESS);
}


void* kepiting(void *arg)
{
    
}
 
int main(void)
{

    pthread_create(&(tid1), NULL, &Lohan, NULL);
    pthread_create(&(tid2), NULL, &Kepiting, NULL);
 
    pthread_join(tid1, NULL);
    pthread_join(tid2, NULL);
 
    return 0;
}

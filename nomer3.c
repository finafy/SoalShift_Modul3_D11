#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
 
pthread_t tid1;
pthread_t tid2;
int status;
int status_louhan=100,status_kepiting=100;

 
void* Lohan(void *arg)
{
	status=0;
	while(status_louhan>0)
	{
		sleep(3);
		status_louhan = status_louhan-15;
	}
	status=1;printf("Game Over\n");exit(EXIT_SUCCESS);
}


void* kepiting(void *arg)
{
	status=0;
		while(status_kepiting>0)
		{
			sleep(20);
			status_kepiting=status_kepiting-10;
		}
		status=1;printf("Game Over\n");exit(EXIT_SUCCESS);
}
 
int main(void)
{

    pthread_create(&(tid1), NULL, &Lohan, NULL);
    pthread_create(&(tid2), NULL, &kepiting, NULL);
 
	while(status!=1)
	{	
		int m;
		printf("%d\n",status_louhan);
		printf("%d\n",status_kepiting);
		printf("1.Beri makan Lohan\n2.Beri makan Kepiting\n");
		scanf("%d",&m);
		if(m==1){
		    status_louhan=status_louhan+10;
		}
		else if(m==2){
    		    status_kepiting=status_kepiting+10;
		}
		if(status_louhan>100 | status_kepiting>100){
		    printf("Game Over\n");
		    return 0;
		}
	}
	return 0;

}

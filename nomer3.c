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
		status_l=status_l-10;
	}
	status=1;printf("Game Over\n");exit(EXIT_SUCCESS);
}


void* kepiting(void *arg)
{
	status=0;
  	status_k=100;
		while(status_k>0)
		{
			sleep(20);
			status_k=status_k-10;
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
		printf("%d\n",status_l);
		printf("%d\n",status_k);
		printf("1.Beri makan Lohan\n2.Beri makan Kepiting\n");
		scanf("%d",&m);
		if(m==1) {status_l+=10;}
		else if(m==2) {status_k+=10;}
	}
	return 0;

}

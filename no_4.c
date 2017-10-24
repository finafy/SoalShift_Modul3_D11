
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
 
pthread_t tid1;
pthread_t tid2;
int status;
int nomor;
int i;
int result;
int iter;
int simpan[20];
int faktor;
int hasil[20];
 
void* tulis(void *arg)
{
    status = 0;
    iter = 0;
    i=0;
    printf("Masukan nomor ");
    result = scanf ("%d", &nomor); 
    while (result != EOF)
    {
	simpan [i] = nomor;
    	
	for (iter=1;iter<=simpan[i];iter++)
	{
	   faktor*=i;
	}
	
	hasil[i] = faktor;
	i++;
    }
 
    status = 1;
}


#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_t tid[2];
int poin1=0,poin2=0;
int total1=16,total2=16;
int lubang1[16]={0},lubang2[16]={0};

void* player1(void *arg)
{
	unsigned long i = 0;
	int Tebak;
		tebakan=(int)no;
		if(lubang1[tebakan-1]==1) {skor1++; printf("pemain 1 menambah nilai\n");}
		else {skor2++; printf("pemain 2 menambah nilai\n");}
}
void* player2(void *arg);
{
	
	int Tebak;
	tebakan=(int)no;
		if(lubang2[tebakan-1]==1) {skor2++; printf("pemain 2 menambah nilai\n");}
		else {skor1++; printf("pemain 1 menambah nilai\n");}
}
int main()
{

return 0;
}

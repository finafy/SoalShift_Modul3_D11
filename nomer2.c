#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_t tid[2];
int poin1=0,poin2=0;
int total1=16,total2=16;
int lubang1[16]={0},lubang2[16]={0};
int status,nomer,lihat;
char nomer1[100],nomer2[100];
void* player1(void *arg)
{
	unsigned long i = 0;
	int tebak;
		if(lubang1[tebak-1]==1) {skor1++; printf("pemain 1 menambah nilai\n");}
		else {skor2++; printf("pemain 2 menambah nilai\n");}
}
void* player2(void *arg);
{
	
	int tebak;
		if(lubang2[tebak-1]==1) {skor2++; printf("pemain 2 menambah nilai\n");}
		else {skor1++; printf("pemain 1 menambah nilai\n");}
}
int main(void)
{
	int i = 0;
	int err;
	char argument[100];
	char nama[100];
	int isi;
	printf("Nick player 1 = ");
	scanf("%s",no1);
	printf("Nick player 2 = ");
	scanf("%s",no2);
	while(skor1<10 && skor2<10)
	{
		printf("mau lihat skor\n 1.Iya\n 0.Tidak");
		scanf("%d",&lihat);
		if(lihat) printf("%s poinnya %d\n%s poinnya %d\n",no1,skor1,no2,skor2);
		if(status%2!=0){
			printf("%s | berapa lubang yang diisi ? ",no1);
			scanf("%d",&isi);
			for(int i=0;i<isi;i++){
			    printf("lubang ");
			    scanf("%d",&no); if(lubang1[no-1]==0){ lubang1[no-1]=1; total1--;}
			    if(total1<1 && total2<1){ printf("game seri\n"); return 0;};
			}
			printf("\n%s silahkan menebak 4 lubang \n",no2);
			for(int i=0;i<4;i++){
			    scanf("%d",&no);
			     pthread_create(&(tid1), NULL, &player1, NULL);
			}
		}

return 0;
}

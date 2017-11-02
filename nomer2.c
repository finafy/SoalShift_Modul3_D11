#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
pthread_t tid[2];
int skor1=0,skor2=0;
int flag=1,no,pilih;
int total1=16,total2=16;
int lubang1[16]={0},lubang2[16]={0};
char no1[100],no2[100];
void* sys(void *arg)       
{
	unsigned long i = 0;
	int tebakan;
	pthread_t id = pthread_self();
	if(pthread_equal(id,tid[0])){
		tebakan=(int)no;
		if(lubang1[tebakan-1]==1) {skor1++; printf("pemain 1 menambah nilai\n");}
		else {skor2++; printf("pemain 2 menambah nilai\n");}
	}
	else if(pthread_equal(id,tid[1])) {
		tebakan=(int)no;
		if(lubang2[tebakan-1]==1) {skor2++; printf("pemain 2 menambah nilai\n");}
		else {skor1++; printf("pemain 1 menambah nilai\n");}
	}
	return NULL;
}
int main(void)
{
	int i = 0;
	int err;
	char argument[100];
	char nama[100];
	int tanya;
	printf("nama pemain 1 = ");
	scanf("%s",no1);
	printf("nama pemain 2 = ");
	scanf("%s",no2);
	while(skor1<10 && skor2<10)
	{
		printf("mau lihat skor? [0/1]");
		scanf("%d",&pilih);
		if(pilih) printf("%s skornya %d\n%s skornya %d\n",no1,skor1,no2,skor2);
		if(flag%2!=0){
			printf("%s | mau berapa lubang yang diisi ? ",no1);
			scanf("%d",&tanya);
			for(int i=0;i<tanya;i++){
			    printf("lubang ");
			    scanf("%d",&no); if(lubang1[no-1]==0){ lubang1[no-1]=1; total1--;}
			    if(total1<1 && total2<1){ printf("game seri, selamat\n"); return 0;};
			}
			printf("\ngiliran %s menebak 4 lubang \n",no2);
			for(int i=0;i<4;i++){
			    scanf("%d",&no);
			    err = pthread_create(&(tid[0]), NULL, &sys, NULL);
			}		
		}
		else{
			printf("%s | mau berapa lubang yang diisi ? ",no2);
			scanf("%d",&tanya);
			for(int i=0;i<tanya;i++){
			    printf("lubang ");
			    scanf("%d",&no); if(lubang2[no-1]==0){ lubang2[no-1]=1; total2--;}
			    if(total1<1 && total2<1){ printf("game seri, selamat\n"); return 0;};
			}
			printf("\ngiliran %s menebak 4 lubang \n",no1);
			for(int i=0;i<4;i++){
			    scanf("%d",&no);
			    err = pthread_create(&(tid[1]), NULL, &sys, NULL);
			}		
		}
	flag++;
	sleep(1);
	}
	if(skor1<skor2) printf("pemenangnya adalah %s\n",no2);
	else printf("pemenangnya adalah %s\n",no1);

	return 0;
}

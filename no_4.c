
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
 
 
void* tulis(void *ptr)
{
    int *simpan = (int*) ptr;
    int iter;
    int faktor;
    
    faktor=1;
    for (iter=1;iter<=*simpan;iter++)
    {
	faktor*=iter;
    }
    
    printf ("Hasil %d! = %d\n", *simpan, faktor);

}

int main(void)
{
    pthread_t tid[30];
    int a;
    int i;
    int j;
    int z;
    int az1, az2, az3;
    int n;
    int number;
    char apa;
    int save[30];

    n=0;
    while(1)
    {
	scanf ("%d", &number);
	scanf ("%c", &apa);
	save[n] = number;
	n++;
	if (apa == '\n') break;
    }
    
    //mengurutkan
    for (i = 0; i < n; i++)
    {
       for (j = i + 1; j < n; j++)
       {
          if (save[i] > save[j])
          {
             a =  save[i];
             save[i] = save[j];
             save[j] = a;
           }
        }
    }
 
    az1=save[2];
    pthread_create(&(tid[0]),NULL,&tulis,&az1);

    az2=save[1];
    pthread_create(&(tid[1]),NULL,&tulis,&az2);

    az3=save[0];
    pthread_create(&(tid[2]),NULL,&tulis,&az3);



    /*for (i=0;i<n;i++){
	az=save[i];
	pthread_create(&(tid[i]),NULL,&tulis,&az);//membuat thread
    }*/
    
	
    for (z=0;z<n;z++){
	pthread_join(tid[z],NULL);
    }
    return 0;
}


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


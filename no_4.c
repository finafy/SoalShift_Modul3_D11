
#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
 
pthread_t tid[30];  
void* tulis(void *ptr)
{
    int simpan = (int) ptr;
    int iter;
    int faktor;
    
    faktor=1;
    for (iter=1;iter<=simpan;iter++)
    {
	faktor*=iter;
    }
    
    printf ("Hasil %d! = %d\n", simpan, faktor);

}

int main(int argc, char **argv)
{
	int a=0;
	int x, t, i, j, z;
	int save [50];

	for(a=1; a<argc; a++)
		{
			x= atoi (argv [a]);
			save[a] = x;

		}

    	//mengurutkan
   	 for (i = 1; i < argc; i++)
    	{
       		for (j = i + 1; j < argc; j++)
       		{
          		if (save[i] < save[j])
          		{
             			t =  save[i];
             			save[i] = save[j];
             			save[j] = t;
           		}
        	}
    	}
 
	for(a=1; a<argc; a++)
		{
			z= save[a];
			pthread_create(&tid[a], NULL, tulis, (void*) z);
		}

	for(a=0; a<argc; a++)
		{
			pthread_join(tid[a], NULL);
		}    

	return 0;
}

#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid [50];

void *search (void *argv)
{
    FILE *text;
    char simpan [1000];
    char kata [100];
    int count;

    strcpy(kata,argv);

    count=0;

    text = fopen ("home/fina/Downloads/Novel.txt","r");
    while (!feof(text)){
	fscanf (text, "%s", simpan);
	if (strstr(simpan,argv) !=NULL) count++;
    }
    fclose(text);
    printf ("%s = %d\n", kata, count);
    
}

int main(int argc, char **argv)
{
	int a=0;

	for(a=1; a<argc; a++)
		{
			pthread_create(&tid[a], NULL, search, (void*)argv[a]);
		}

	for(a=0; a<argc; a++)
		{
			pthread_join(tid[a], NULL);
		}
	return 0;
}

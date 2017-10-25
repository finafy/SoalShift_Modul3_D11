#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

void search(void *ptr)
{
    FILE *txt;
    txt = fopen ("home/fina/Downloads/Novel.txt", "r");
    int M = strlen(pat);
    int N = strlen(txt);
    

    int i;  
    /* A loop to slide pat[] one by one */
    for (i = 0; i <= N - M; i++)
    {
        int j;
  
        /* For current index i, check for pattern match */
        for (j = 0; j < M; j++){
            if (txt[i+j] != pat[j])
                break;
	}
 
        if (j == M)  // if pat[0...M-1] = txt[i, i+1, ...i+M-1]
           printf("Pattern found at index %d n", i);
    }
}

int main (){

pthread_t tid[30];
int i;
char string [20];

i=0;

while(scanf ("%s", string) != EOF){

pthread_create(&(tid[i]),NULL,&search,string);
pthread_join(tid[i],NULL);

i++;
}


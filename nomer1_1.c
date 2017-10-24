#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <string.h>

#define  SHZISE 100

void main()
{
	int *shm;
        key_t key = 1234;

        int shmid = shmget(key, SHZISE, IPC_CREAT | 0666);
        shm = shmat(shmid, NULL, 0);




        printf("Program 1: %d\n", *value);
        shmdt(value);
        shmctl(shmid, IPC_RMID, NULL);
}

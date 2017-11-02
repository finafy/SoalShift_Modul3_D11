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
        shm = (int*)shmat(shmid, NULL, 0);
	char senjata[6][8]={"MP4A1","PM2-V1","SPR-3","SS2-V5","SPG1-V3","MINE"};
	
	while(1)
	{
		printf("1.Lihat Stock Senjata\n2.beli Senjata\n");
		int pilihan,i;
		scanf("%d",&pilihan);
		if(pilihan==1)
		{
			for(i=0;i<6;i++)
			{ printf("%s-%d\n",senjata[i],shm[i]); }

		}
		else if(pilihan==2)
		{
			 char weapon[8];int jumlah;int i;
                        scanf("%s %d",&weapon,&jumlah);

                        for(i=0;i<6;i++)
                        { if(strcmp(weapon,senjata[i])==0) if(shm[i]>jumlah) shm[i]=shm[i]-jumlah;}

		}

	}
        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);
}

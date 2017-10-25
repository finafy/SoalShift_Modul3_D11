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
		printf("1.Lihat Stock Senjata\n2.Tambah Stock Senjata\n");
		int pilihan,i;
		scanf("%d",&pilihan);
		if(pilihan==1)
		{
			for(i=0;i<6;i++)
			{ if(shm[i]>0)printf("%s-%d\n",senjata[i],shm[i]); }

		}
		else if(pilihan==2)
		{
			char weapon[8];int jumlah;
			scanf("%s %d",&weapon,&jumlah);
			if(strcmp(weapon,senjata[0])==0) shm[0]=shm[0]+jumlah;
			else if(strcmp(weapon,senjata[1])==0) shm[1]=shm[1]+jumlah;
			else if(strcmp(weapon,senjata[2])==0) shm[2]=shm[2]+jumlah;
			else if(strcmp(weapon,senjata[3])==0) shm[3]=shm[3]+jumlah;
			else if(strcmp(weapon,senjata[4])==0) shm[4]=shm[4]+jumlah;
			else if(strcmp(weapon,senjata[5])==0) shm[5]=shm[5]+jumlah;
		}

	}
        shmdt(shm);
        shmctl(shmid, IPC_RMID, NULL);
}

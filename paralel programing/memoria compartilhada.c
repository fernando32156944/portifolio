/*
Nome: Fernando Mauadie da Silva Machado
TIA:32156944
*/
#include <errno.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#define ADDKEY 123
// OBS: as vezes � necessario rodar o progama mais de uma vez para aparecer o processo filho.

int main() 
{
    int p;
    p =0;
    int *x; 
    int shmid ; /* identificador da mem�ria comum */
    int size = 1024 ;
    char *path="./" ;
    if (( shmid = shmget(ftok(path,ADDKEY), size, IPC_CREAT|
    IPC_EXCL|SHM_R|SHM_W)) == -1) 
    {
        perror("Erro no shmget") ;
        exit(1) ;
    }
    x =(int*) shmat(shmid, NULL, 0);
    *x = p;
    pid_t pid = fork();
    if(pid == 0)
    {
        *x = *x+1;
        printf("valor de x alterado pelo filho: %d\n",*x);
    }
    else
    {
        *x = *x+2;
        printf("valor de x: %d\n",*x);
    }
    return 0;
}


#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

#define KEY 41234L
#define PERM 00666

int main() {

    int id;
    //struct sembuf up[1]  =  {0,  1, SEM_UNDO};
    //struct sembuf down[1] = {0, -1, SEM_UNDO};

	if ((id = semget(KEY, 1, 0)) < 0) { 
		perror(" Még nem létezik a szemafor. ");
		exit(-1);
	}
    
    semctl(id, 0, SETVAL, 1);
    
    exit(0);
}

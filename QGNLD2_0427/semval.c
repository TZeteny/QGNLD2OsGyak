#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

#define KEY 41234L
#define PERM 00666

int main() {
    int 	id;
    int value;

	if ((id = semget(KEY, 1, 0)) < 0) { 
		perror(" Még nem létezik a szemafor. ");
		exit(-1);
	}

    value = semctl(id, 0, GETVAL, 0);
    printf("Az érték: %d\n", value);
    
	exit(0);
}


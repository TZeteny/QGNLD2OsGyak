#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdio.h>
#include <stdlib.h>

#define KEY 41234L
#define PERM 00666

main() {
    int id; /* A szemafor azonosítója */
    int N = 2;
    int n;
 
	if ((id = semget(KEY, N, 0)) < 0) { /* Még nem létezik. */
		if ((id = semget(KEY, N, PERM | IPC_CREAT)) < 0) {
		 	perror(" A szemafor nem nyitható meg. ");
			exit(-1);
		}
	}
	else    {
		perror(" Már létezik a szemafor. ");
		exit(0);
	}
    
    //for (n = 0; n < N; n++) {
	    if (semctl(id, n, SETVAL, 0) < 0) {
		    perror(" Nem lehetett inicializálni. ");
	    }
        else {
    		puts(" Kész és inicializált a szemafor. ");
	    }
    //}

	exit(0);
}

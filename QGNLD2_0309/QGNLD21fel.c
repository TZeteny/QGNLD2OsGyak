#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void) {

	int status;

	if ( ( status = system("who -b") ) < 0 )
		perror("system() error");

	if (WIFEXITED(status) )
		printf("Norm befejezes, visszadott ertek = %d\n", WEXITSTATUS(status));

	if ( ( status = system("boci") ) < 0 )
                perror("system() error");

        if (WIFEXITED(status) )
                printf("Norm befejezes, visszadott ertek = %d\n", WEXITSTATUS(status));

}

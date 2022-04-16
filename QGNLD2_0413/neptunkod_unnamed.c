#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
	int pipefd[2];
	pid_t cpid;
	char buf;
	char szoveg[32];
	int ret;

	if (pipe(pipefd) == -1) {
		perror("pipe");
		exit(-1);
	}
	
	cpid = fork();
	if (cpid == -1) {
	perror("fork");
	exit(-1);
	}

	if (cpid == 0) {
		close(pipefd[0]);
		
		strcpy(szoveg,"XY neptunkod\0");
		write(pipefd[1], szoveg, strlen(szoveg));
		
		close(pipefd[1]);

   		exit(0);
	}
	
	else {

   		close(pipefd[1]);
		
		while (read(pipefd[0], &buf, 1) > 0) {
		printf("%c",buf);
		}
		
		close(pipefd[0]);
		
		wait(NULL);
		
		exit(0);
	}
}

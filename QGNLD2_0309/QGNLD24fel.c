#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
	char *args[] = {"./4ex", NULL};
	pid_t pid = fork();
	
	if (pid != 0) {
		wait(NULL);
	}
	
	printf("PID: %d\n", getpid());
	execv(args[0], args);
	
	
	return 0;
}

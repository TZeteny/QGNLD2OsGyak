#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main() {
	pid_t pid;
	int sig;
        int i = 0;
    
	printf("Give the pid of 29a\n");
	scanf("%d",&pid);
    
    //while(i == 0){
    while(i < 5){
	kill(pid, SIGUSR1);
	kill(pid, SIGUSR2);
	sleep(2);
    i++;
	}
    
    kill(pid, SIGTERM);
        
    return 0;    
}

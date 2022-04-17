#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>

int main() {
	int fd, ret;
	char buf[32];
	pid_t cpid;
	
	buf[0]=0;
	
	ret=mkfifo("neptunkod",00666);
	if (ret == -1) {
	    perror("mkfifo()");
	    exit(-1);
	}
	
	fd=open("neptunkod",O_RDWR);
	if (fd == -1) {
	    perror("open() hiba!");
	    exit(-1);
	}
	
	if (cpid == 0) {
		strcpy(buf,"Tozser Zeteny\0");
		write(fd,buf,strlen(buf));
		
		close(fd);
		exit(0);
	}
	
	else {
		ret=read(fd,buf,32);
		printf("A szoveg: %s", buf);
		
		close(fd);
		unlink("neptunkod");
		
		wait(NULL);
		
		exit(0);
	}
	
}

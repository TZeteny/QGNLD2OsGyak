#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

int main()
{
	int fd, ret;
	char buf[32];

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

	strcpy(buf,"Tozser Zeteny\0");
	write(fd,buf,strlen(buf));

	ret=read(fd,buf,32);
	printf("%s\n", buf);

	close(fd);

	unlink("neptunkod");
}
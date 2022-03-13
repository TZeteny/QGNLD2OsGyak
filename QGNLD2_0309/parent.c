#include <stdio.h>
#include <unistd.h>

int main() {
	//printf("parent\n");
	char *args[] = {"./child", NULL};
	execv(args[0], args);
	
	printf("parent end\n");
	
	return 0;
}

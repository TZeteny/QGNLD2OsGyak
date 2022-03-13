#include <stdio.h>
#include <stdlib.h>

int main() {
	int r;
	char command[50];
	
	printf ("Give a unix command: ");
	scanf("%[^\n]", command);
	//printf("%s\n", command);
	
	r = system(command);
	
	return r;
}

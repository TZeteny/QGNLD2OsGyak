/*Irjon C nyelvu programokat, ami
SIGUSR1 signal erkeztekor noveli egy valtozo erteket
SIGUSR2 signal hatasara pedig kiirja a kepernyore az aktualis erteket.
a masik program pedig: futtataskor signal-t kuld az adott processznek*/

#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int variable = 0;
int true = 0;

void handler1() {
	variable += 1;
	printf("increased\n");

}

void handler2() {
	printf("The current value %d\n", variable);
}

int main() {
	while(true == 0){
	    signal(SIGUSR1, (void (*)()) handler1);
	    signal(SIGUSR2, (void (*)()) handler2);
	}
    
	return 0;
}

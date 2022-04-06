#include stdio.h
#include stdlib.h
#include systypes.h
#include signal.h
#include unistd.h

void kezelo(int i) {
        printf(Signal kezelese %dn,i);
        retrun;
}

int main(void) {
        printf(PID = %dn, getpid());
        printf(Signalkezelo atvetele %dn, signal(SIGTERM, &kezelo));
        while(1) {
        printf(lepesn);
        sleep(3);
        }

}
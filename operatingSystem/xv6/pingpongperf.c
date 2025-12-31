#include <signal.h>
#include <stdio.h>
#include <sys/signal.h>
#include <sys/wait.h>
#include <unistd.h>

int nbyte;

void handle(int signum) {
    printf("n read: %d\n", nbyte);
    fflush(NULL);
    nbyte = 0;
    alarm(1);
}

int main() {
    int p2c[2];
    int c2p[2];
    char buf[1];

    pipe(p2c);
    pipe(c2p);

    if(fork() == 0) {
        close(p2c[1]);
        close(c2p[0]);
        signal(SIGALRM, handle);
        alarm(1);

        while (1) {
            read(p2c[0], buf, 1);

            write(c2p[1], buf, 1);

            nbyte++;
        }

        close(p2c[0]);
        close(c2p[1]);
    } else {
        close(p2c[0]);
        close(c2p[1]);
        signal(SIGALRM, handle);
        alarm(1);

        while (1) {
            buf[0] = 0;
            write(p2c[1], buf, 1);

            read(c2p[0], buf, 1);

            nbyte++;
        }

        close(p2c[1]);
        close(c2p[0]);
    }
}

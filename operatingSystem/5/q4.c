#include <stdio.h>
#include <unistd.h>

int main() {
    printf("Hello from p1\n");

    pid_t p2 = fork();
    if (p2 == 0) {
        printf("Hello from p2\n");
        return 0;
    }

    pid_t p3 = fork();
    if (p3 == 0) {
        printf("Hello from p3\n");

        pid_t p4 = fork();
        if (p4 == 0) {
            printf("Hello from p4\n");
            return 0;
        }

        pid_t p5 = fork();
        if (p5 == 0) {
            printf("Hello from p5\n");
        }
    }
}

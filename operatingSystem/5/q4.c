#include <stdio.h>
#include <unistd.h>

int main() {
    // p1 membuat p2
    pid_t p2 = fork();
    if (p2 == 0) {
        // p2
        printf("Hello from p2\n");
        return 0;
    }

    // p1 membuat p3
    pid_t p3 = fork();
    if (p3 == 0) {
        // p3
        printf("Hello from p3\n");

        // p3 membuat p4
        pid_t p4 = fork();
        if (p4 == 0) {
            // p4
            printf("Hello from p4\n");
            return 0;
        }

        // p3 membuat p5
        pid_t p5 = fork();
        if (p5 == 0) {
            // p5
            printf("Hello from p5\n");
            return 0;
        }

        return 0;
    }

    // p1
    printf("Hello from p1\n");
    return 0;
}

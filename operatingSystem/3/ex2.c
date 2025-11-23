#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUF_SIZE 100
#define MAX_COUNT 200

void childProcess(void);
void parentProcess(void);

int main() {
    pid_t pid = fork();

    if (pid == 0) {
        childProcess();
    } else {
        parentProcess();
    }
}

void childProcess(void) {
    for (int i = 0; i <= MAX_COUNT; i++) {
        printf("   This line is from child, value = %d\n", i);
    }
    printf("   *** Child process is done ***\n");
}

void parentProcess(void) {
    for (int i = 1; i <= MAX_COUNT; i++)
        printf("This line is from parent, value = %d\n", i);

    printf("*** Parent is done ***\n");
}

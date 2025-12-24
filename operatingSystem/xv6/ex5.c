#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
    if (fork() == 0) {
        write(1, "hello ", 6);
        exit(0);
    } else {
        wait(0);
        write(1, "world\n", 6);
    }
}

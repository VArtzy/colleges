#include <fcntl.h>
#include <unistd.h>

int main() {
    char *argv[2];

    argv[0] = "cat";
    argv[1] = 0;
    
    if (fork() == 0) {
        close(0);
        open("input.txt", O_RDONLY);
        execv("/bin/cat", argv);
    }
}

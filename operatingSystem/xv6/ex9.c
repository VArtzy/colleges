#include <sys/fcntl.h>
#include <sys/stat.h>
#include <unistd.h>

int main() {
    mkdir("/dir", 0777);
    int fd = open("/dir/file", O_WRONLY);
    close(fd);
    mknod("/console", 1, 1);
}

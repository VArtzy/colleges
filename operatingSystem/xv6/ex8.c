#include <sys/fcntl.h>
#include <unistd.h>

int main() {
    chdir("/a");
    chdir("b");
    open("c", O_RDONLY);
    
    open("/a/b/c", O_RDONLY);
}

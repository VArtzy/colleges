#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    char buf[512];
    int n;

    for(;;) {
        n = read(0, buf, sizeof buf);

        if (n == 0) break;

        if (n < 0) {
            dprintf(2, "read error\n");
            exit(1);
        }

        if (write(1, buf, n) != n) {
            dprintf(2, "write error\n");
            exit(1);
        }
    }
}

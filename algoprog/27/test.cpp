#include <algorithm>
#include <cstdio>
#include <cstdlib>
static bool isCrazy = false;

void interact_with_human(void) {
    if ((isCrazy = true)) {
        printf("kill\n");
    } else {
        printf("nice\n");
    }
}

int main() {
    // interact_with_human();
    
    printf("Hi\n");
    system("date");
}

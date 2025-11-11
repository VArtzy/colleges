#include <stdio.h>
#include <string.h>

int palindrome(char *str) {
    int s = 0;
    int e = strlen(str) - 1;

    while (s < e) {
        if (str[s] != str[e]) {
            return 1;
        }
        s++; e--;
    }
    return 0;
}

int main() {
    printf("%d\n", palindrome("kodok"));
    printf("%d\n", palindrome("while"));
}

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int hitungVokal(char* string) {
    int count = 0;

    for (int i = 0; i < strlen(string); i++) {
        char c = tolower((unsigned char) string[i]); // jadiin lowercase biar gampang soalnya stringnya sama aja
        if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o') {
            count++;
        } 
    }

    return count;
}

int main() {
    printf("%d\n", hitungVokal("Hello World"));
}

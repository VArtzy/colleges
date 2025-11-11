#include <stdio.h>
#include <string.h>

int cekAnagram(char* str1, char* str2) {
    int count = 0;
    int len = strlen(str1);

    for (int i = 0; i < len; i++) {
        for (int j = 0; j < strlen(str2); j++) {
            if (str2[j] == str1[i]) {
                count++;
                str2[j] = ' ';
                break;
            }
        }
    }

    return count == len;
}

int main() {
    char str1[10] = "listen";
    char str2[10] = "silent";
    char str3[10] = "bunda";
    char str4[10] = "rahma";
    char str5[10] = "kodok";
    char str6[10] = "dokuk";
    printf("%d\n", cekAnagram(str1, str2));
    printf("%d\n", cekAnagram(str3, str4));
    printf("%d\n", cekAnagram(str5, str6));
}

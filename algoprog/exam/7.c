#include <stdio.h>

void main() {
    int angka[] = {25, 12, 4, 18}; int n = 4;
    int i, j, temp;

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (angka[j] > angka[j + 1]) {
                // tukar elemen 
                temp = angka[j];
                angka[j] = angka[j + 1]; angka[j + 1] = temp;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        printf("%d " ,angka[i]);
    }
    printf("\n");
}

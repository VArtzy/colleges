#include <stdio.h>

int main() {
    int gajiKotor;

    printf("Masukkan gaji kotor: ");
    scanf("%d", &gajiKotor);

    int pajak = gajiKotor * 0.10;

    int gajiBersih = gajiKotor - pajak;

    printf("Gaji bersih adalah: %d\n", gajiBersih);
}

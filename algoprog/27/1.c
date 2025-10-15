#include <stdio.h>

int main() {
    FILE *fin = fopen("angka.txt", "r");
    FILE *fgenap = fopen("genap.txt", "w");
    FILE *fganjil = fopen("ganjil.txt", "w");
    int n;

    if (!fin || !fgenap || !fganjil) {
        printf("Gagal membuka file.\n");
        return 1;
    }

    while (fscanf(fin, "%d", &n) == 1) {
        if (n % 2 == 0)
            fprintf(fgenap, "%d ", n);
        else
            fprintf(fganjil, "%d ", n);
    }

    fclose(fin);
    fclose(fgenap);
    fclose(fganjil);
    printf("Pemrosesan selesai.\n");
    return 0;
}

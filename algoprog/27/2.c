#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Masukkan jumlah siswa: ");
    scanf("%d", &n);

    float *nilai = (float*) malloc(n * sizeof(float));
    if (nilai == NULL) {
        printf("Memori gagal dialokasikan.\n");
        return 1;
    }

    float total = 0;
    for (int i = 0; i < n; i++) {
        printf("Masukkan nilai mahasiswa ke-%d: ", i + 1);
        scanf("%f", &nilai[i]);
        total += nilai[i];
    }

    printf("Rata-rata nilai: %.2f\n", total / n);
    free(nilai);
    return 0;
}

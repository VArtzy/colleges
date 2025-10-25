typedef struct {
    char nama[20];
    int umur;
    int noreg;
} Siswa;

#include <stdio.h>
#include <string.h>
#include <time.h>
int main() {
    clock_t start, end;
    double cpu_time_used;
    start = clock();

    FILE *fp = fopen("siswa_1000.txt", "r");

    char key[20];
    _Bool found = 0;
    printf("Cari siswa dengan nama: ");
    scanf("%s", key);

    Siswa siswa[1000];
    for (int i = 0; fscanf(fp, "%s %d %d", siswa[i].nama, &siswa[i].umur, &siswa[i].noreg) == 3; i++) {
        Siswa *s = &siswa[i];
        if(strcmp(key, s->nama) == 0) {
            printf("Nama: %s\nUmur: %d\nNo registrasi: %d\n", s->nama, s->umur, s->noreg);
            found = 1; break;
        }
    }
    if (!found) {
        printf("Data siswa dengan nama %s tidak ditemukan!\n", key);
    }

    fclose(fp);

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("\nWaktu eksekusi: %.6f detik\n", cpu_time_used);
}

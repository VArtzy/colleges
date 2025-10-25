typedef struct {
    char nama[20];
    int umur;
    int noreg;
} Siswa;

#include <stdio.h>
#include <string.h>
int main() {
    FILE *fp = fopen("siswa.txt", "r");

    char key[20];
    _Bool found = 0;
    printf("Cari siswa dengan nama: ");
    scanf("%s", key);

    Siswa siswa[10];
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
}

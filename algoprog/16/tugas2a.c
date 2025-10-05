#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned int NIP;
    char nama[20];
    char alamat[100];
    char telepon[16];
    char jabatan[20];
    char golongan[2];
    unsigned int gaji;
} pegawai;

int main() {
    pegawai pegawai;
    printf("%-20s:", "Masukkan NIP");
    scanf("%u", &pegawai.NIP);
    printf("%-20s:", "Masukkan Nama");
    scanf(" %[^\n]", pegawai.nama);
    printf("%-20s:", "Masukkan Alamat");
    scanf(" %[^\n]", pegawai.alamat);
    printf("%-20s:", "Masukkan No HP");
    scanf("%s", pegawai.telepon);
    printf("%-20s:", "Masukkan jabatan");
    scanf("%s", pegawai.jabatan);
    printf("%-20s:", "Masukkan Golongan");
    scanf("%s", pegawai.golongan);

    if (strcmp(pegawai.golongan, "D1") == 0) {
        pegawai.gaji = 3000000;
    } else if (strcmp(pegawai.golongan, "D2") == 0) {
        pegawai.gaji = 2500000;
    } else if (strcmp(pegawai.golongan, "D3") == 0) {
        pegawai.gaji = 2000000;
    } else {
        printf("Runtime Error: masukkan golongan yang benar! (D1, D2, D3)");
        return EXIT_FAILURE;
    }
    
    setlocale(LC_NUMERIC, "id_ID.UTF-8");

    printf("\nGaji Pokok Anda: Rp%.0f\n", (double)pegawai.gaji);
    return EXIT_SUCCESS;
}

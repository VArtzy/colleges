#include <stdio.h>

int main() {
    char nama[100];
    int nim;
    char jurusan[100];

    printf("Masukkan Nama: ");
    scanf("%[^\n]", nama);

    printf("Masukkan NIM: ");
    scanf("%d", &nim);

    printf("Masukkan Jurusan: ");
    scanf(" %[^\n]", jurusan);

    FILE *fp = fopen("biodata.txt", "w"); // atau bisa pakai mode "a" untuk append file
    if (!fp) {
        printf("Gagal menulis file\n");
        return 1;
    }
    fprintf(fp, "%s | %d | %s\n", nama, nim, jurusan);
    fclose(fp);
    
    printf("Data berhasil ditulis ke biodata.txt\n");
}

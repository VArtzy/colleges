#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union {
    _Bool buku: 1;
    _Bool majalah: 1;
} tipe;

typedef struct {
    char *judul;
    unsigned char terbit;
    tipe tipe;
}  item;

typedef struct {
    char judul[100];
    int terbit;
    enum { BUKU, MAJALAH } tipe;
}  item_unoptimize;

int main() {
    const unsigned short MIN = 1900;
    item item;
    item_unoptimize item2;
    size_t bufsize = 0;
    char *judul = NULL;
    char jenis[7];
    unsigned short terbit;
    printf("Masukkan judul: ");
    getline(&judul, &bufsize, stdin);
    item.judul = judul;
    strncpy(item2.judul, judul, sizeof(item2.judul) - 1);

    printf("Masukkan tahun terbit: ");
    scanf("%hu", &terbit);
    item.terbit = terbit - MIN;
    item2.terbit = terbit;

    printf("Buku atau Majalah: ");
    scanf("%s", jenis);
    if (strcmp(jenis, "Buku") == 0) {
        item.tipe.buku = 1;
        item2.tipe = BUKU;
    } else if (strcmp(jenis, "Majalah") == 0) {
        item.tipe.majalah = 0;
        item2.tipe = MAJALAH;
    } else {
        printf("Jenis tidak valid, silahkan pilih 'Buku' atau 'Majalah'!\n");
        return 1;
    }

    printf("\nJudul: %s", item.judul);
    printf("Tahun terbit: %d\n", item.terbit + MIN);
    printf("Jenis media: %s\n\n", item.tipe.buku ? "Buku" : "Majalah");
    printf("Ukuran struct item \n`typedef struct {\n     char *judul;\n     unsigned char terbit;\n     tipe tipe; \n}  item;`\n: %lubytes + %lubytes (judul) = %lubytes\n\n", sizeof(item), bufsize, sizeof(item) + bufsize);
    printf("Ukuran struct item unoptimize \n`typedef struct {\n     char judul[100];\n     int terbit;\n     enum { BUKU, MAJALAH }\n tipe; \n}  item_unoptimize;`\n: %lubytes\n", sizeof(item2));
    free(item.judul);
}

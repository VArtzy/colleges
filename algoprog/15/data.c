/*
 * Gambaran: struktur struct dan union menggunakan struct item yang berisi informasi umum/inklusif dari koleksi (termasuk jenis media) dan memuat union yang berisi detail dari setiap jenis koleksi.
 *
 * Penjelasan: struct item adalah koleksi berisi informasi umum/inklusif dari koleksi seperti judul, tahun terbit dan jenis media lalu union media menentukan detail dari setiap jenis koleksi lewat struct buku berisi ISBN dan halaman atau struct majalah berisi ISSN dan edisi.
 * Struct yang saya buat sudah dioptimisasi sehingga sangat hemat memori, bahkan saya punya versi yang lebih hemat dan dinamik dengan menggunakan char * untuk judul (file test.c)
 *
 * Kelebihan pengunaan union: union memanfaatkan memory layout yang satu tapi bisa menerima input field dengan tipe/data yang berbeda dengan mengambil tipe/data yang terbesar.
 * Sudah jelas union dapat menghemat memori dengan membuat struct item memiliki satu jenis detail media dalam satu waktu yang mungkin bisa memakan memori jika kita masukkkan kedua detail sekaligus (hemat sebanyak ukuran union).
 * Selain itu, kode menjadi skalabel karena tidak banyak redudancy serta lebih fleksibel bahkan dapat memanfaatkan konversi tipe/data yang sebenarnya sama tapi berbeda interface atau tipe datanya.
 *
 * Note: dikerjakan sesuai intruksi. Apabila ada yang kelupaan atau perlu dikoreksi, mohon beritahu agar dapat revisi. Struct Item juga bisa dibuat dan ditampilkan dalam bentuk array of Item (jika jamak). Terimakasih untuk dosen.
 */

#include <stdio.h>
#include <string.h>

typedef struct {
    char isbn[13];
    unsigned short halaman;
} Buku;

typedef struct {
    char issn[13];
    unsigned short edisi;
} Majalah;

typedef union {
    Buku buku;
    Majalah majalah;
} Media;

typedef enum {
    BUKU,
    MAJALAH
} Jenis;

typedef struct {
    char judul[100];
    unsigned short terbit;
    Jenis jenis;
    Media media;
} Item;

int main() {
    Item item;
    char jenis[8];
    
    printf("Masukkan judul: ");
    scanf("%[^\n]", item.judul);
    printf("Masukkan tahun terbit: ");
    scanf("%hu", &item.terbit);
    printf("Masukkan jenis media: ");
    scanf("%s", jenis);

    if (strcmp(jenis, "Buku") == 0) {
        item.jenis = BUKU;
    } else if (strcmp(jenis, "Majalah") == 0) {
        item.jenis = MAJALAH;
    } else {
        printf("Jenis media tidak valid, silahkan masukan 'Buku' atau 'Majalah'!\n");
        return 1;
    }

    switch (item.jenis) {
        case BUKU:
            printf("Masukkan ISBN: ");
            scanf("%s", item.media.buku.isbn);
            printf("Masukkan jumlah halaman: ");
            scanf("%hu", &item.media.buku.halaman);
            break;
        case MAJALAH:
            printf("Masukkan ISSN: ");
            scanf("%s", item.media.majalah.issn);
            printf("Masukkan edisi: ");
            scanf("%hu", &item.media.majalah.edisi);
            break;
    }

    printf("Judul: %s\n", item.judul);
    printf("Tahun terbit: %hu\n", item.terbit);
    if (item.jenis == BUKU) {
        printf("Jenis media: Buku\n");
        printf("ISBN: %s\n", item.media.buku.isbn);
        printf("Jumlah halaman: %hu\n", item.media.buku.halaman);
    } else if (item.jenis == MAJALAH) {
        printf("Jenis media: Majalah\n");
        printf("ISSN: %s\n", item.media.majalah.issn);
        printf("Edisi: %hu\n", item.media.majalah.edisi);
    }
}

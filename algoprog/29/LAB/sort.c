#include <stdio.h>
#include <string.h>

#include "project.h"

/* Mengurutkan buku berdasarkan nama secara ascending (bubble sort) */
static void sortNama(buku_t book[], size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        for (size_t j = 0; j < n - i - 1; j++) {
            if (strcmp(book[j].nama, book[j + 1].nama) > 0) {
                buku_t temp = book[j];
                book[j] = book[j + 1];
                book[j + 1] = temp;
            }
        }
    }
}

/* Mengurutkan buku berdasarkan harga secara descending (selection sort) */
static void sortHarga(buku_t book[], size_t n) {
    for (size_t i = 0; i < n - 1; i++) {
        size_t maxIndex = i;
        for (size_t j = i + 1; j < n; j++) {
            if (book[j].harga > book[maxIndex].harga) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            buku_t temp = book[i];
            book[i] = book[maxIndex];
            book[maxIndex] = temp;
        }
    }
}

/* Menampilkan menu sorting dan mengeksekusi pilihan pengguna */
void sortMenu(const buku_t *book, size_t n) {
    if (book == NULL || n == 0) {
        printf("Tidak ada data buku\n");
        return;
    }

    buku_t sorted[n];
    memcpy(sorted, book, n * sizeof(buku_t));

    int pilihan;
    do {
        printf("\n=== MENU SORTING BUKU ===\n");
        printf("1. Urutkan berdasarkan Nama (Ascending) [Bubble Sort]\n");
        printf("2. Urutkan berdasarkan Harga (Descending) [Selection Sort]\n");
        printf("3. Kembali ke Menu Utama\n");
        printf("Pilih menu: ");
        if (scanf("%d", &pilihan) != 1) {
            printf("Input tidak valid. Coba lagi.\n");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF) {}
            pilihan = 0;
            continue;
        }
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}

        switch (pilihan) {
            case 1:
                sortNama(sorted, n);
                for (size_t i = 0; i < n; i++) {
                    printf("Nama: %s\nJenis: %s\nKode: %s\nHarga: %.2f\n\n",
                           sorted[i].nama,
                           sorted[i].jenis,
                           sorted[i].kode,
                           sorted[i].harga);
                }
                break;
            case 2:
                sortHarga(sorted, n);
                for (size_t i = 0; i < n; i++) {
                    printf("Nama: %s\nJenis: %s\nKode: %s\nHarga: %.2f\n\n",
                           sorted[i].nama,
                           sorted[i].jenis,
                           sorted[i].kode,
                           sorted[i].harga);
                }
                break;
            case 3:
                printf("Kembali ke menu utama...\n");
                break;
            default:
                printf("Pilihan tidak valid. Coba lagi.\n");
                break;
        }
    } while(pilihan != 3);
}

#include <stdio.h>
#include <string.h>
typedef struct {
    char name[100];
    char jenis[50];
    char kode[10];
    int price;
} Buku;
void sortNama(Buku book[], int n) {
    for (int i = 1; i < n; i++) {
        for (int j = n - 1; j >= i; j--) {
            if(strcmp(book[j].name, book[j + 1].name)) {
                Buku tmp = book[j];
                book[j] = book[j - 1];
                book[j - 1] = tmp;
            }
        }
    }
}
void sortHarga(Buku book[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int idx = i;
        for (int j = i + 1; j < n; j++) {
            if (book[j].price > book[i].price) {
                idx = j;
            }
            Buku tmp = book[i];
            book[i] = book[idx];
            book[idx] = tmp;
        }
    }
}

void sortMenu(Buku book[], int n) {
    if (n == 0) {
        printf("Tidak ada data buku");
        return;
    }

    int pilihan;
    do {
        printf("\n=== MENU SORTING BUKU ===\n");
        printf("1. Urutkan berdasarkan Nama (Ascending) [Bubble Sort]\n");
        printf("2. Urutkan berdasarkan Harga (Descending) [Selection Sort]\n");
        printf("3. Kembali ke Menu Utama\n");
        printf("Pilih menu: ");
        scanf("%d", &pilihan);
        getchar();

        switch (pilihan) {
            case 1:
                sortMenu(book, n);
                for (int i = 0; i < n; i++) {
                    printf("Name: %s\nJenis: %s\nKode: %s\nPrice: %d\n\n", book[i].name, book[i].jenis, book[i].kode, book[i].price);
                }
                break;
            case 2:
                sortHarga(book, n);
                for (int i = 0; i < n; i++) {
                    printf("Name: %s\nJenis: %s\nKode: %s\nPrice: %d\n\n", book[i].name, book[i].jenis, book[i].kode, book[i].price);
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

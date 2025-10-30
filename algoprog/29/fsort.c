#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100];
    char jenis[50];
    char kode[10];
    int price;
} Buku;

void sortNama(Buku book[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(book[j].name, book[j + 1].name) > 0) {
                Buku temp = book[j];
                book[j] = book[j + 1];
                book[j + 1] = temp;
            }
        }
    }
}
void sortHarga(Buku book[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (book[j].price > book[maxIndex].price) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            Buku temp = book[i];
            book[i] = book[maxIndex];
            book[maxIndex] = temp;
        }
    }
}

void sortMenu(Buku book[], int n) {
    Buku sorted[n];
    memcpy(sorted, book, n * sizeof(Buku));

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
                sortNama(sorted, n);
                for (int i = 0; i < n; i++) {
                    printf("Name: %s\nJenis: %s\nKode: %s\nPrice: %d\n\n", sorted[i].name, sorted[i].jenis, sorted[i].kode, sorted[i].price);
                }
                break;
            case 2:
                sortHarga(sorted, n);
                for (int i = 0; i < n; i++) {
                    printf("Name: %s\nJenis: %s\nKode: %s\nPrice: %d\n\n", sorted[i].name, sorted[i].jenis, sorted[i].kode, sorted[i].price);
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

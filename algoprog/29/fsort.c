#include <stdio.h>
#include <string.h>

typedef struct {
    char name[100];
    char jenis[50];
    char kode[10];
    int price;
} Buku;

void printBuku(Buku book[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Name: %s\nJenis: %s\nKode: %s\nPrice: %d\n\n", book[i].name, book[i].jenis, book[i].kode, book[i].price);
    }
}

void sortNama(Buku book[], int n) {
    Buku sorted[n];
    memcpy(sorted, book, n * sizeof(Buku));
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (strcmp(sorted[j].name, sorted[j + 1].name) > 0) {
                Buku temp = sorted[j];
                sorted[j] = sorted[j + 1];
                sorted[j + 1] = temp;
            }
        }
    }
    printBuku(sorted, n);
}
void sortHarga(Buku book[], int n) {
    Buku sorted[n];
    memcpy(sorted, book, n * sizeof(Buku));
    for (int i = 0; i < n - 1; i++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (sorted[j].price > sorted[maxIndex].price) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            Buku temp = sorted[i];
            sorted[i] = sorted[maxIndex];
            sorted[maxIndex] = temp;
        }
    }
    printBuku(sorted, n);
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
                sortNama(book, n);
                break;
            case 2:
                sortHarga(book, n);
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

int main() {
    Buku daftarBuku[10] = {
        {"Pemrograman C Dasar", "Pemrograman", "BK001", 75000},
        {"Struktur Data", "Komputer", "BK002", 90000},
        {"Algoritma Pemrograman", "Komputer", "BK003", 85000},
        {"Jaringan Komputer", "Teknologi", "BK004", 95000},
        {"Basis Data", "Komputer", "BK005", 88000},
        {"Sistem Operasi", "Komputer", "BK006", 92000},
        {"Kecerdasan Buatan", "Teknologi", "BK007", 120000},
        {"Desain UI/UX", "Desain", "BK008", 70000},
        {"Manajemen Proyek TI", "Manajemen", "BK009", 80000},
        {"Statistika dan Probabilitas", "Matematika", "BK010", 65000}
    };

    sortMenu(daftarBuku, 10);

    for (int i = 0; i < 10; i++) {
        printf("Name: %s\nJenis: %s\nKode: %s\nPrice: %d\n\n", daftarBuku[i].name, daftarBuku[i].jenis, daftarBuku[i].kode, daftarBuku[i].price);
    }
}

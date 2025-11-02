#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct {
    char kodeBuku[10];
    char namaBuku[50];
    char jenisBuku[30];
    struct {
        int jumlahTerjual;
        double hargaBuku;
    } DataBuku;
} Buku;

void displayBuku(Buku *b, int count);
void deleteBuku(Buku *b, int *count);

int main() {
    Buku *buku = malloc(MAX * sizeof(Buku));
    int count = 0;
    int choice;

    // Load data buku dari file (jika ada)
    FILE *fp = fopen("databuku.txt", "r");
    if (fp != NULL) {
        while (fscanf(fp, "%s %s %s %lf",
                      buku[count].kodeBuku,
                      buku[count].namaBuku,
                      buku[count].jenisBuku,
                      &buku[count].DataBuku.hargaBuku) == 4) {
            count++;
                      }
        fclose(fp);
    }

    do {
        printf("\n===== MENU UTAMA =====\n");
        printf("1. Input Buku\n");
        printf("2. View Buku\n");
        printf("3. View History Penjualan\n");
        printf("4. Delete Buku\n");
        printf("5. Delete History Penjualan\n");
        printf("6. Save & Exit\n");
        printf("7. Transaksi Penjualan\n");
        printf("8. Sorting Buku\n");
        printf("=======================\n");
        printf("Masukkan pilihan: ");
        scanf("%d", &choice);

        switch (choice) {
            //case 1:
                //addBuku();
                //break;
            case 2:
                displayBuku(buku, count);
                break;
            //case 3:
                //displayHistory();
                //break;
            case 4:
                deleteBuku(buku, &count);
                break;
            //case 5:
                //deleteHistory();
                //break;
            //case 6:
                //saveToFile();
                //printf("Data disimpan. Keluar dari program...\n");
                //break;
            //case 7:
                //transaksiPenjualan(buku, count);
                //break;
            //case 8:
                //sortBuku();
                //break;
            default:
                printf("Pilihan tidak valid!\n");
        }
    } while (choice != 6);

    free(buku);
    return 0;
}
void displayBuku(Buku *b, int count) {
    if (count == 0) {
        printf("\n⚠️  Tidak ada data buku.\n");
        return;
    }

    printf("\n=== DAFTAR BUKU ===\n");
    printf("%-10s %-25s %-15s %-10s\n", "Kode", "Nama Buku", "Jenis", "Harga");
    printf("--------------------------------------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%-10s %-25s %-15s Rp%.2lf\n",
               b[i].kodeBuku,
               b[i].namaBuku,
               b[i].jenisBuku,
               b[i].DataBuku.hargaBuku);
    }
}

void deleteBuku(Buku *b, int *count) {
    if (*count == 0) {
        printf("\n⚠️  Tidak ada data buku untuk dihapus.\n");
        return;
    }

    char kode[10];
    printf("\nMasukkan kode buku yang ingin dihapus: ");
    scanf("%s", kode);

    int found = -1;
    for (int i = 0; i < *count; i++) {
        if (strcmp(b[i].kodeBuku, kode) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("Buku dengan kode '%s' tidak ditemukan.\n", kode);
        return;
    }

    for (int i = found; i < *count - 1; i++) {
        b[i] = b[i + 1];
    }
    (*count)--;

    printf("Buku dengan kode '%s' berhasil dihapus.\n", kode);
}
// Created by Jeri Irawan on A 2025/10/31.
//

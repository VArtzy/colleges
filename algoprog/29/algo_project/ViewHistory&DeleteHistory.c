#include <stdio.h>

#include "project.h"

/* Menampilkan seluruh history transaksi yang tersimpan */
void viewHistory(const history_t *history, size_t count) {
    if (history == NULL || count == 0) {
        printf("Belum ada data history.\n");
        return;
    }

    printf("\n=== HISTORY TRANSAKSI PENJUALAN ===\n");

    for (size_t i = 0; i < count; ++i) {
        printf("%zu. Kode Buku: %s | Jumlah: %d | Total Harga: %.2f\n",
               i + 1,
               history[i].kode,
               history[i].jumlah,
               history[i].total);
    }
}


/* Menghapus entri history tertentu berdasarkan pilihan pengguna */
void deleteHistory(history_t *history, size_t *count) {
    if (history == NULL || *count == 0) {
        printf("File history.txt belum ada atau kosong.\n");
        return;
    }

    printf("\n=== DAFTAR HISTORY PENJUALAN ===\n");
    for (size_t i = 0; i < *count; i++) {
        printf("%zu. %s | Jumlah: %d | Total Harga: %.2f\n",
               i + 1,
               history[i].kode,
               history[i].jumlah,
               history[i].total);
    }

    int hapus;
    printf("\nMasukkan nomor data yang ingin dihapus: ");
    if (scanf("%d", &hapus) != 1) {
        printf("Input tidak valid.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return;
    }

    if (hapus < 1 || (size_t)hapus > *count) {
        printf("Nomor tidak valid.\n");
        return;
    }

    for (size_t i = (size_t)(hapus - 1); i < *count - 1; i++) {
        history[i] = history[i + 1];
    }
    (*count)--;

    printf("Data successfully delete.\n");
}

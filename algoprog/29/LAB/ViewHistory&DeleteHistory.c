#include <stdio.h>
#include <stdlib.h>

struct History {
    char kodeBuku[10];
    int jumlahTerjual;
    double totalHarga;
};


void viewHistory() {
    FILE *file = fopen("history.txt", "r");
    if (file == NULL) {
        printf("Belum ada data history.\n");
        return;
    }

    struct History data;
    int index = 1;

    printf("\n=== HISTORY TRANSAKSI PENJUALAN ===\n");

    while (fscanf(file, "%s %d %lf",
                  data.kodeBuku,
                  &data.jumlahTerjual,
                  &data.totalHarga) == 3) {
        printf("%d. Kode Buku: %s | Jumlah: %d | Total Harga: %.2lf\n",
               index, data.kodeBuku, data.jumlahTerjual, data.totalHarga);
        index++;
    }

    if (index == 1) {
        printf("Belum ada transaksi yang tercatat.\n");
    }

    fclose(file);
}


void deleteHistory() {
    FILE *file = fopen("history.txt", "r");
    if (file == NULL) {
        printf("File history.txt belum ada atau kosong.\n");
        return;
    }

    struct History history[100];
    int count = 0;

    while (fscanf(file, "%s %d %lf",
                  history[count].kodeBuku,
                  &history[count].jumlahTerjual,
                  &history[count].totalHarga) == 3) {
        count++;
    }
    fclose(file);

    if (count == 0) {
        printf("Tidak ada data untuk dihapus.\n");
        return;
    }

    printf("\n=== DAFTAR HISTORY PENJUALAN ===\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s | Jumlah: %d | Total Harga: %.2lf\n",
               i + 1,
               history[i].kodeBuku,
               history[i].jumlahTerjual,
               history[i].totalHarga);
    }

    int hapus;
    printf("\nMasukkan nomor data yang ingin dihapus: ");
    scanf("%d", &hapus);

    if (hapus < 1 || hapus > count) {
        printf("Nomor tidak valid.\n");
        return;
    }

    for (int i = hapus - 1; i < count - 1; i++) {
        history[i] = history[i + 1];
    }
    count--;

    file = fopen("history.txt", "w");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%s %d %.2lf\n",
                history[i].kodeBuku,
                history[i].jumlahTerjual,
                history[i].totalHarga);
    }
    fclose(file);

    printf("Data Successfully delete..\n");
}

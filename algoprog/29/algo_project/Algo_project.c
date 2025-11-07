/* Kelompok:
   FELIX                     | 2902701533 | Computer Science
   FARREL NIKOSON            | 2902704895 | Computer Science
   ZAHRA NAZIFA WIBOWO       | 2902700820 | Computer Science
   ATTHALLAH KAFKA PUTRA DERYANDRI | 2902692384 | Computer Science
   JERI IRAWAN               | 2902692844 | Computer Science
*/

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "project.h"

static const char *DATA_BUKU_FILE = "databuku.txt";
static const char *DATA_HISTORY_FILE = "history.txt";

static void addBuku(buku_t **bukuList, size_t *bukuCount);
static void addHistory(history_t **historyList, size_t *historyCount, const buku_t *bukuList, size_t bukuCount);
static void menu(buku_t **bukuList, size_t *bukuCount, history_t **historyList, size_t *historyCount);
static void saveAll(buku_t *bukuList, size_t bukuCount, history_t *historyList, size_t historyCount);

/* Fungsi utama program: inisialisasi data dan menjalankan menu */
int main(void) {
    size_t bukuCount = 0;
    size_t historyCount = 0;

    buku_t *bukuList = load_databuku(DATA_BUKU_FILE, &bukuCount);
    history_t *historyList = load_history(DATA_HISTORY_FILE, &historyCount);

    menu(&bukuList, &bukuCount, &historyList, &historyCount);

    saveAll(bukuList, bukuCount, historyList, historyCount);

    free(bukuList);
    free(historyList);

    return 0;
}

/* Menambahkan data buku baru ke daftar buku */
static void addBuku(buku_t **bukuList, size_t *bukuCount) {
    char nama[128];
    char jenis[64];
    char harga_str[64];

    printf("\n-- Input Data Buku Baru --\n");
    printf("Nama buku: ");
    input_garis(nama, sizeof(nama));
    if (strlen(nama) == 0) {
        printf("Nama buku tidak boleh kosong.\n");
        return;
    }

    printf("Jenis buku: ");
    input_garis(jenis, sizeof(jenis));
    if (strlen(jenis) == 0) {
        printf("Jenis buku tidak boleh kosong.\n");
        return;
    }

    printf("Harga buku (contoh: 75000.50): ");
    input_garis(harga_str, sizeof(harga_str));
    double harga = strtod(harga_str, NULL);
    if (harga <= 0.0) {
        printf("Harga tidak valid.\n");
        return;
    }

    size_t before = *bukuCount;
    buku_t *updated = tambah_buku(*bukuList, bukuCount, nama, jenis, harga);
    if (updated != NULL) {
        *bukuList = updated;
    }

    if (*bukuCount > before && *bukuList != NULL) {
        printf("Buku berhasil ditambahkan dengan kode: %s\n", (*bukuList)[*bukuCount - 1].kode);
    } else {
        printf("Gagal menambahkan buku baru.\n");
    }
}

/* Mencatat transaksi penjualan ke dalam history */
static void addHistory(history_t **historyList, size_t *historyCount, const buku_t *bukuList, size_t bukuCount) {
    if (bukuList == NULL || bukuCount == 0) {
        printf("Belum ada data buku. Tambahkan data buku terlebih dahulu.\n");
        return;
    }

    char kode[16];
    char jumlah_str[32];

    printf("\n-- Input Transaksi Penjualan --\n");
    printf("Masukkan kode buku: ");
    input_garis(kode, sizeof(kode));
    if (strlen(kode) == 0) {
        printf("Kode buku tidak boleh kosong.\n");
        return;
    }

    const buku_t *selected = NULL;
    for (size_t i = 0; i < bukuCount; ++i) {
        if (strcmp(bukuList[i].kode, kode) == 0) {
            selected = &bukuList[i];
            break;
        }
    }

    if (selected == NULL) {
        printf("Buku dengan kode '%s' tidak ditemukan.\n", kode);
        return;
    }

    printf("Masukkan jumlah terjual: ");
    input_garis(jumlah_str, sizeof(jumlah_str));
    long jumlah = strtol(jumlah_str, NULL, 10);
    if (jumlah <= 0 || jumlah > INT_MAX) {
        printf("Jumlah tidak valid.\n");
        return;
    }

    history_t *tmp = realloc(*historyList, (*historyCount + 1) * sizeof(history_t));
    if (tmp == NULL) {
        printf("Gagal mengalokasi memori untuk history.\n");
        return;
    }

    *historyList = tmp;
    history_t *entry = &(*historyList)[*historyCount];

    strncpy(entry->kode, kode, sizeof(entry->kode));
    entry->kode[sizeof(entry->kode) - 1] = '\0';
    entry->jumlah = (int)jumlah;
    entry->total = selected->harga * (double)jumlah;

    (*historyCount)++;

    printf("History berhasil ditambahkan. Total harga: %.2f\n", entry->total);
}

/* Menyajikan dan menangani interaksi menu utama */
static void menu(buku_t **bukuList, size_t *bukuCount, history_t **historyList, size_t *historyCount) {
    char buffer[32];
    int running = 1;

    while (running) {
        printf("\nMenu Utama:\n");
        printf("1. Input data buku baru\n");
        printf("2. Lihat history transaksi penjualan\n");
        printf("3. Lihat seluruh data buku yang tersedia\n");
        printf("4. Hapus history penjualan tertentu\n");
        printf("5. Hapus data buku tertentu\n");
        printf("6. Exit\n");
        printf("7. Input transaksi penjualan\n");
        printf("8. Sorting data buku\n");
        printf("Masukkan pilihan: ");

        input_garis(buffer, sizeof(buffer));
        int choice = atoi(buffer);

        switch (choice) {
            case 1:
                {
                    size_t before = *bukuCount;
                    addBuku(bukuList, bukuCount);
                    if (*bukuCount > before) {
                        if (!save_databuku(DATA_BUKU_FILE, *bukuList, *bukuCount)) {
                            printf("Peringatan: perubahan buku gagal disimpan.\n");
                        }
                    }
                }
                break;
            case 2:
                viewHistory(*historyList, *historyCount);
                break;
            case 3:
                displayBuku(*bukuList, *bukuCount);
                break;
            case 4:
                {
                    size_t before = *historyCount;
                    deleteHistory(*historyList, historyCount);
                    if (*historyCount < before) {
                        if (!save_history(DATA_HISTORY_FILE, *historyList, *historyCount)) {
                            printf("Peringatan: perubahan history gagal disimpan.\n");
                        }
                    }
                }
                break;
            case 5:
                {
                    size_t before = *bukuCount;
                    deleteBuku(*bukuList, bukuCount);
                    if (*bukuCount < before) {
                        if (!save_databuku(DATA_BUKU_FILE, *bukuList, *bukuCount)) {
                            printf("Peringatan: perubahan buku gagal disimpan.\n");
                        }
                    }
                }
                break;
            case 6:
                printf("Exiting program...\n");
                running = 0;
                break;
            case 7:
                {
                    size_t before = *historyCount;
                    addHistory(historyList, historyCount, *bukuList, *bukuCount);
                    if (*historyCount > before) {
                        if (!save_history(DATA_HISTORY_FILE, *historyList, *historyCount)) {
                            printf("Peringatan: perubahan history gagal disimpan.\n");
                        }
                    }
                }
                break;
            case 8:
                sortMenu(*bukuList, *bukuCount);
                break;
            default:
                printf("Pilihan tidak valid! Silakan coba lagi.\n");
                break;
        }
    }
}

/* Menyimpan seluruh perubahan data buku dan history ke file */
static void saveAll(buku_t *bukuList, size_t bukuCount, history_t *historyList, size_t historyCount) {
    if (!save_databuku(DATA_BUKU_FILE, bukuList, bukuCount)) {
        printf("Peringatan: gagal menyimpan databuku.txt\n");
    }
    if (!save_history(DATA_HISTORY_FILE, historyList, historyCount)) {
        printf("Peringatan: gagal menyimpan history.txt\n");
    }
}

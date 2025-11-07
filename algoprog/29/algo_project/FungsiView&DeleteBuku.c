#include <stdint.h>
#include <stdio.h>
#include <string.h>

#include "project.h"

/* Menampilkan daftar buku lengkap dalam tabel */
void displayBuku(const buku_t *b, size_t count) {
    if (count == 0) {
        printf("\n⚠️  Tidak ada data buku.\n");
        return;
    }

    printf("\n=== DAFTAR BUKU ===\n");
    printf("%-10s %-25s %-15s %-10s\n", "Kode", "Nama Buku", "Jenis", "Harga");
    printf("--------------------------------------------------------------\n");
    for (size_t i = 0; i < count; i++) {
        printf("%-10s %-25s %-15s Rp%.2f\n",
               b[i].kode,
               b[i].nama,
               b[i].jenis,
               b[i].harga);
    }
}

/* Menghapus satu buku dari daftar berdasarkan kode */
void deleteBuku(buku_t *b, size_t *count) {
    if (b == NULL || *count == 0) {
        printf("\n⚠️  Tidak ada data buku untuk dihapus.\n");
        return;
    }

    char kode[16];
    printf("\nMasukkan kode buku yang ingin dihapus: ");
    if (scanf("%15s", kode) != 1) {
        printf("Input tidak valid.\n");
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {}
        return;
    }
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF) {}

    size_t found = SIZE_MAX;
    for (size_t i = 0; i < *count; i++) {
        if (strcmp(b[i].kode, kode) == 0) {
            found = i;
            break;
        }
    }

    if (found == SIZE_MAX) {
        printf("Buku dengan kode '%s' tidak ditemukan.\n", kode);
        return;
    }

    for (size_t i = found; i < *count - 1; i++) {
        b[i] = b[i + 1];
    }
    (*count)--;

    printf("Buku dengan kode '%s' berhasil dihapus.\n", kode);
}
// Created by Jeri Irawan on A 2025/10/31.
//

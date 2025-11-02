#ifndef PROJECT_H
#define PROJECT_H

#include <stddef.h>

typedef struct {
    char kode[16];
    char nama[128];
    char jenis[64];
    double harga;
} buku_t;

typedef struct {
    char kode[16];
    int jumlah;
    double total;
} history_t;

/* input_data_buku_baru_dan_exit.c */
buku_t *load_databuku(const char *filename, size_t *out_count);
int save_databuku(const char *filename, buku_t *arr, size_t count);
history_t *load_history(const char *filename, size_t *out_count);
int save_history(const char *filename, history_t *arr, size_t count);
void generate_kode(buku_t *arr, size_t count, char *out_kode, size_t out_len);
buku_t *tambah_buku(buku_t *arr, size_t *count, const char *nama, const char *jenis, double harga);
void tampilkan_buku_singkat(buku_t *arr, size_t count);
void input_garis(char *buf, size_t len);

/* FungsiView&DeleteBuku.c */
void displayBuku(const buku_t *b, size_t count);
void deleteBuku(buku_t *b, size_t *count);

/* ViewHistory&DeleteHistory.c */
void viewHistory(const history_t *history, size_t count);
void deleteHistory(history_t *history, size_t *count);

/* sort.c */
void sortMenu(const buku_t *book, size_t n);

#endif /* PROJECT_H */

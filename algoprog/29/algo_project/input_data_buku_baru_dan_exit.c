#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "project.h"

#define LINEBUF 512

/* Memuat data buku dari file databuku.txt */
/* jika file tidak ada, inisialisasi array kosong */
buku_t *load_databuku(const char *filename, size_t *out_count) {
    FILE *fp = fopen(filename, "r");
    buku_t *arr = NULL;
    size_t cap = 0, n = 0;
    char line[LINEBUF];

    *out_count = 0;
    if (!fp) {
        /* file tidak ditemukan -> kembalikan array kosong */
        return NULL;
    }

    while (fgets(line, sizeof(line), fp)) {
        /* hapus newline */
        char *p = strchr(line, '\n');
        if (p) *p = '\0';

        /* split berdasarkan '|' */
        char *tok;
        char *saveptr = NULL;
        char temp[LINEBUF];
        strncpy(temp, line, sizeof(temp));
        temp[sizeof(temp)-1] = '\0';

        tok = strtok_r(temp, "|", &saveptr);
        if (!tok) continue;
        char kode[16]; strncpy(kode, tok, sizeof(kode)); kode[sizeof(kode)-1] = '\0';

        tok = strtok_r(NULL, "|", &saveptr);
        if (!tok) continue;
        char nama[128]; strncpy(nama, tok, sizeof(nama)); nama[sizeof(nama)-1] = '\0';

        tok = strtok_r(NULL, "|", &saveptr);
        if (!tok) continue;
        char jenis[64]; strncpy(jenis, tok, sizeof(jenis)); jenis[sizeof(jenis)-1] = '\0';

        tok = strtok_r(NULL, "|", &saveptr);
        if (!tok) continue;
        double harga = atof(tok);

        if (n + 1 > cap) {
            size_t newcap = cap == 0 ? 8 : cap * 2;
            buku_t *tmp = realloc(arr, newcap * sizeof(buku_t));
            if (!tmp) {
                fprintf(stderr, "gagal mengalokasi memori\n");
                fclose(fp);
                free(arr);
                *out_count = 0;
                return NULL;
            }
            arr = tmp;
            cap = newcap;
        }
        strncpy(arr[n].kode, kode, sizeof(arr[n].kode));
        strncpy(arr[n].nama, nama, sizeof(arr[n].nama));
        strncpy(arr[n].jenis, jenis, sizeof(arr[n].jenis));
        arr[n].harga = harga;
        n++;
    }

    fclose(fp);
    *out_count = n;
    return arr;
}

/* Menyimpan seluruh data buku ke databuku.txt (overwrite) */
int save_databuku(const char *filename, buku_t *arr, size_t count) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        fprintf(stderr, "gagal membuka %s untuk menulis\n", filename);
        return 0;
    }
    for (size_t i = 0; i < count; ++i) {
        /* format: kode|nama|jenis|harga\n */
        fprintf(fp, "%s|%s|%s|%.2f\n", arr[i].kode, arr[i].nama, arr[i].jenis, arr[i].harga);
    }
    fclose(fp);
    return 1;
}

/* Memuat data history transaksi dari history.txt jika tersedia */
history_t *load_history(const char *filename, size_t *out_count) {
    FILE *fp = fopen(filename, "r");
    history_t *arr = NULL;
    size_t cap = 0, n = 0;
    char line[LINEBUF];

    *out_count = 0;
    if (!fp) {
        return NULL;
    }

    while (fgets(line, sizeof(line), fp)) {
        char *p = strchr(line, '\n'); if (p) *p = '\0';
        char *tok, *saveptr = NULL;
        char temp[LINEBUF]; strncpy(temp, line, sizeof(temp)); temp[sizeof(temp)-1] = '\0';

        tok = strtok_r(temp, "|", &saveptr);
        if (!tok) continue;
        char kode[16]; strncpy(kode, tok, sizeof(kode)); kode[sizeof(kode)-1] = '\0';

        tok = strtok_r(NULL, "|", &saveptr);
        if (!tok) continue;
        int jumlah = atoi(tok);

        tok = strtok_r(NULL, "|", &saveptr);
        if (!tok) continue;
        double total = atof(tok);

        if (n + 1 > cap) {
            size_t newcap = cap == 0 ? 8 : cap * 2;
            history_t *tmp = realloc(arr, newcap * sizeof(history_t));
            if (!tmp) {
                fprintf(stderr, "gagal mengalokasi memori\n");
                fclose(fp);
                free(arr);
                *out_count = 0;
                return NULL;
            }
            arr = tmp;
            cap = newcap;
        }
        strncpy(arr[n].kode, kode, sizeof(arr[n].kode));
        arr[n].jumlah = jumlah;
        arr[n].total = total;
        n++;
    }
    fclose(fp);
    *out_count = n;
    return arr;
}

/* Menyimpan seluruh data history ke history.txt (overwrite) */
int save_history(const char *filename, history_t *arr, size_t count) {
    FILE *fp = fopen(filename, "w");
    if (!fp) {
        fprintf(stderr, "gagal membuka %s untuk menulis\n", filename);
        return 0;
    }
    for (size_t i = 0; i < count; ++i) {
        fprintf(fp, "%s|%d|%.2f\n", arr[i].kode, arr[i].jumlah, arr[i].total);
    }
    fclose(fp);
    return 1;
}

/* Mencari nomor terbesar dari kode buku bertipe bkNNN */
/* mengembalikan angka terbesar yang ditemukan (0 bila tidak ada) */
int cari_nomor_terakhir(buku_t *arr, size_t count) {
    int max = 0;
    for (size_t i = 0; i < count; ++i) {
        /* asumsi kode dimulai dengan "bk" diikuti angka */
        const char *k = arr[i].kode;
        if (strlen(k) >= 5 && (k[0] == 'b' || k[0] == 'B') && (k[1] == 'k' || k[1] == 'K')) {
            int num = atoi(k + 2);
            if (num > max) max = num;
        }
    }
    return max;
}

/* Menghasilkan kode buku baru dengan format bkNNN */
void generate_kode(buku_t *arr, size_t count, char *out_kode, size_t out_len) {
    int last = cari_nomor_terakhir(arr, count);
    int next = last + 1;
    /* format dengan 3 digit */
    snprintf(out_kode, out_len, "bk%03d", next);
}

/* Menambahkan buku baru ke array dinamis buku */
buku_t *tambah_buku(buku_t *arr, size_t *count, const char *nama, const char *jenis, double harga) {
    size_t n = *count;
    buku_t *tmp = realloc(arr, (n + 1) * sizeof(buku_t));
    if (!tmp) {
        fprintf(stderr, "gagal mengalokasi memori untuk menambah buku\n");
        return arr; /* kembalikan arr lama (kemungkinan null) */
    }
    arr = tmp;
    /* generate kode berdasarkan data saat ini */
    char kode[16];
    generate_kode(arr, n, kode, sizeof(kode));
    strncpy(arr[n].kode, kode, sizeof(arr[n].kode));
    strncpy(arr[n].nama, nama, sizeof(arr[n].nama));
    strncpy(arr[n].jenis, jenis, sizeof(arr[n].jenis));
    arr[n].harga = harga;
    *count = n + 1;
    return arr;
}

/* Menampilkan ringkasan daftar buku (index, kode, nama, harga) */
void tampilkan_buku_singkat(buku_t *arr, size_t count) {
    if (count == 0 || arr == NULL) {
        printf("tidak ada data buku.\n");
        return;
    }
    printf("daftar buku:\n");
    for (size_t i = 0; i < count; ++i) {
        printf("%zu. %s | %s | %.2f\n", i+1, arr[i].kode, arr[i].nama, arr[i].harga);
    }
}

/* Membaca input baris secara aman dan menghapus newline */
void input_garis(char *buf, size_t len) {
    if (!fgets(buf, (int)len, stdin)) {
        buf[0] = '\0';
        return;
    }
    char *p = strchr(buf, '\n');
    if (p) *p = '\0';
}

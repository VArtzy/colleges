#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINEBUF 512

/* struktur buku */
typedef struct {
    char kode[16];
    char nama[128];
    char jenis[64];
    double harga;
} buku_t;

/* struktur history transaksi */
typedef struct {
    char kode[16];
    int jumlah;
    double total;
} history_t;

/* fungsi utama: load buku dari file databuku.txt */
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

/* fungsi utama: simpan buku ke databuku.txt (overwrite) */
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

/* fungsi utama: load history dari history.txt (jika ada) */
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

/* fungsi utama: simpan history ke history.txt (overwrite) */
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

/* fungsi bantu: cari nomor terakhir dari kode buku berbentuk bkNNN */
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

/* fungsi utama: generate kode buku otomatis sesuai format bk001, bk002, dst */
void generate_kode(buku_t *arr, size_t count, char *out_kode, size_t out_len) {
    int last = cari_nomor_terakhir(arr, count);
    int next = last + 1;
    /* format dengan 3 digit */
    snprintf(out_kode, out_len, "bk%03d", next);
}

/* fungsi untuk menambah buku ke array (dynamic) */
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

/* fungsi bantu: tampilkan daftar buku singkat (index, kode, nama, harga) */
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

/* fungsi bantu: input string baris aman (menghapus newline) */
void input_garis(char *buf, size_t len) {
    if (!fgets(buf, (int)len, stdin)) {
        buf[0] = '\0';
        return;
    }
    char *p = strchr(buf, '\n');
    if (p) *p = '\0';
}

/* main: menyediakan menu sederhana; hanya menu 1 dan 6 yang diimplementasikan penuh */
int main() {
    const char *file_buku = "databuku.txt";
    const char *file_history = "history.txt";

    buku_t *buku_arr = NULL;
    size_t buku_count = 0;
    history_t *hist_arr = NULL;
    size_t hist_count = 0;

    /* load data awal (jika file ada) */
    buku_arr = load_databuku(file_buku, &buku_count);
    if (!buku_arr) {
        buku_arr = NULL; buku_count = 0;
    }
    hist_arr = load_history(file_history, &hist_count);
    if (!hist_arr) {
        hist_arr = NULL; hist_count = 0;
    }

    int pilihan = 0;
    while (1) {
        printf("\n=== menu utama toko buku \"literasi nusantara jaya\" ===\n");
        printf("1. input data buku baru\n");
        printf("2. view history transaksi penjualan (belum diimplementasikan)\n");
        printf("3. view buku (seluruh data buku yang tersedia) (belum diimplementasikan)\n");
        printf("4. delete history (belum diimplementasikan)\n");
        printf("5. delete buku (belum diimplementasikan)\n");
        printf("6. exit (simpan data terbaru & keluar)\n");
        printf("7. input transaksi penjualan (belum diimplementasikan)\n");
        printf("pilih menu (ketik angka): ");
        char in[32];
        input_garis(in, sizeof(in));
        pilihan = atoi(in);

        if (pilihan == 1) {
            /* menu 1: input data buku baru */
            char nama[128], jenis[64], harga_str[64];
            double harga = 0.0;
            printf("\n-- input data buku baru --\n");
            printf("nama buku: ");
            input_garis(nama, sizeof(nama));
            if (strlen(nama) == 0) {
                printf("nama buku tidak boleh kosong. batal menambah.\n");
                continue;
            }
            printf("jenis buku: ");
            input_garis(jenis, sizeof(jenis));
            if (strlen(jenis) == 0) {
                printf("jenis buku tidak boleh kosong. batal menambah.\n");
                continue;
            }
            printf("harga (contoh: 75000.50): ");
            input_garis(harga_str, sizeof(harga_str));
            harga = atof(harga_str);
            if (harga <= 0.0) {
                printf("harga tidak valid. batal menambah.\n");
                continue;
            }

            buku_arr = tambah_buku(buku_arr, &buku_count, nama, jenis, harga);
            if (buku_arr) {
                printf("data buku berhasil ditambahkan. kode buku: %s\n", buku_arr[buku_count-1].kode);
            } else {
                printf("gagal menambahkan buku.\n");
            }
        } else if (pilihan == 2) {
            /* placeholder: view history */
            printf("\nmenu view history belum diimplementasikan pada tugas ini.\n");
            /* tetap tunjukkan ringkasan minimal agar tidak error */
            if (hist_count == 0 || hist_arr == NULL) {
                printf("tidak ada history.\n");
            } else {
                for (size_t i = 0; i < hist_count; ++i) {
                    printf("%zu. %s | %d | %.2f\n", i+1, hist_arr[i].kode, hist_arr[i].jumlah, hist_arr[i].total);
                }
            }
        } else if (pilihan == 3) {
            /* tampilkan semua buku */
            printf("\n-- view buku (seluruh data buku) --\n");
            tampilkan_buku_singkat(buku_arr, buku_count);
        } else if (pilihan == 4) {
            printf("\nmenu delete history belum diimplementasikan pada tugas ini.\n");
        } else if (pilihan == 5) {
            printf("\nmenu delete buku belum diimplementasikan pada tugas ini.\n");
        } else if (pilihan == 6) {
            /* menu exit: simpan databuku.txt dan history.txt lalu keluar */
            printf("\nmenyimpan data ke file...\n");
            if (save_databuku(file_buku, buku_arr, buku_count)) {
                printf("databuku.txt berhasil disimpan.\n");
            } else {
                printf("gagal menyimpan databuku.txt\n");
            }
            if (save_history(file_history, hist_arr, hist_count)) {
                printf("history.txt berhasil disimpan.\n");
            } else {
                /* jika tidak ada history atau gagal, beri tahu tetapi tetap exit */
                if (hist_arr == NULL && hist_count == 0) {
                    /* tidak ada history untuk disimpan, buat file kosong */
                    FILE *fp = fopen(file_history, "w");
                    if (fp) {
                        fclose(fp);
                        printf("history.txt dibuat kosong.\n");
                    } else {
                        printf("gagal membuat history.txt kosong.\n");
                    }
                } else {
                    printf("gagal menyimpan history.txt\n");
                }
            }
            printf("keluar dari program. sampai jumpa.\n");
            break;
        } else if (pilihan == 7) {
            printf("\nmenu input transaksi penjualan belum diimplementasikan pada tugas ini.\n");
        } else {
            printf("pilihan tidak dikenali, silakan coba lagi.\n");
        }
    }

    /* bersihkan memori sebelum keluar */
    free(buku_arr);
    free(hist_arr);
    return 0;
}

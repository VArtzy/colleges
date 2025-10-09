typedef union {
    _Bool buku: 1;
    _Bool majalah: 1;
} tipe;

typedef struct {
    char *judul;
    unsigned char terbit;
    tipe tipe;
}  __attribute__((packed))item;

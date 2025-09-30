/*
 * Judul:        Tugas 2 - Program Control (Selection & Repetition) + Pointers & Array
 * Nama Lengkap: Farrel Nikoson
 * NIM:          2902704895
 */

#include <stdio.h>

int main() {
    int SIZE = 5; // jumlah nilai ujian
    int nilai[SIZE]; // inisialisasi array

    printf("Masukkan lima nilai ujian: "); // meminta user untuk memasukkan nilai ujian
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", nilai + i); // menggunakan for loop untuk mengisi data
    }

    int tertinggi = *nilai; // inisialisasi nilai variabel tertinggi
    int terendah = *nilai; // inisialisasi nilai variabel terendah
    float rata; // inisialisasi variabel rata

    for (int i = 0; i < SIZE; i++) { 
        int nilai_ = *(nilai + i); // nilai ujian setiap perulangan (agar mudah dibaca)

        if (nilai_ > tertinggi) {
            tertinggi = nilai_; // jika nilai lebih tinggi dari tertinggi, assign nilai ke variabel tertinggi
        } else {}

        if (nilai_ < terendah) {
            terendah = nilai_; // jika nilai lebih rendah dari terendah, assign nilai ke variabel terendah
        } else {}

        rata += nilai_; // setiap perulangan akumulasi nilai ujian
    }
    rata /= SIZE; // akumulasi nilai dibagi jumlah nilai ujian

    for (int i = 0; i < SIZE; i++) {
        printf("Nilai ke-%d: %d\n", i + 1, *(nilai + i)); // menggunakan for loop untuk mencetak data
    }
    printf("Tertinggi = %d\n", tertinggi); // mencetak tertinggi
    printf("Terendah = %d\n", terendah); // mencetak terendah
    printf("Rata-rata = %.2f\n", rata); // mencetak rata-rata
}

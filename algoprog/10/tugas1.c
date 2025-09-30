/*
 * Judul:        Tugas 1 - Format Input dan Output, Operator, Operand, dan Aritmatika
 * Nama Lengkap: Farrel Nikoson
 * NIM:          2902704895
 */

#include <stdio.h>

int main() {
    int SIZE = 3; // jumlah bilangan
    int bilangan[SIZE]; // insialisasi array

    printf("Masukkan tiga bilangan angka: "); // meminta user untuk memassukan tiga bilangan
    scanf("%d %d %d", bilangan, bilangan + 1, bilangan + 2); // mengisi data

    int pertama = *bilangan; // insialisasi bilangan pertama
    int kedua = *(bilangan + 1); // insialisasi bilangan kedua
    int ketiga = *(bilangan + 2); // insialisasi bilangan ketiga

    int jumlah = pertama + kedua + ketiga; // kalkulasi hasil penjumlahan
    int kurang = pertama - kedua - ketiga; // kalkulasi hasil pengurangan
    int kali = pertama * kedua * ketiga; // kalkulasi hasil perkalian
    float bagi = (float)pertama / kedua / ketiga; // kalkulasi hasil pembagian
    float rata = (float)jumlah / SIZE; // kalkulasi hasil rata-rata
    
    printf("Penjumlahan = %d\n", jumlah); // mencetak penjumlahan
    printf("Pengurangan = %d\n", kurang); // mencetak pengurangan
    printf("Perkalian = %d\n", kali); // mencetak perkalian
    printf("Pembagian = %.4f\n", bagi); // mencetak pembagian
    printf("Rata-rata = %.2f\n", rata); // mencetak rata-rata
}

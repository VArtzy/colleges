#include <stdio.h>
char konversiNilai(int nilai) {
    // bisa lakukan validasi jika nilai tidak valid (misal dibawah 0 atau diatas 100)
    if (nilai >= 85 && nilai <= 100) {
        return 'A';
    } else if (nilai >= 70 && nilai <= 84) {
        return 'B';
    } else if (nilai >= 60 && nilai <= 69) {
        return 'C';
    } else if (nilai >= 50 && nilai <= 59) {
        return 'D';
    } else {
        return 'E';
    }
}

int main() {
    printf("49 %c\n", konversiNilai(49));
    printf("50 %c\n", konversiNilai(50));
    printf("60 %c\n", konversiNilai(60));
    printf("70 %c\n", konversiNilai(70));
    printf("85 %c\n", konversiNilai(85));
    printf("100 %c\n", konversiNilai(100));
}

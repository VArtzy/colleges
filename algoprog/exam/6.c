#include <stdio.h>

int main() {

int hasil = 10; int i;
for (i = 1; i < 5; i++) { if (i % 2 == 0) {
hasil = hasil + i;
} else {
hasil = hasil - i;
}
}
printf("Hasil akhir: %d\n", hasil); return 0;
}

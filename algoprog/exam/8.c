#include <stdio.h>
#define SIZE 5

int cariTerbesar(int arr[], int size) {
    int max = arr[0];

    for (int i = 1; i < size; i++) {
        if (max < arr[i]) {
            max = arr[i];
        }
    }

    return max;
}

int main() {
    int arr[SIZE];

    printf("Masukkan 5 angka (pisahkan dengan spasi): ");
    for (int i = 0; i < SIZE; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Nilai terbesar dalam array adalah: %d\n", cariTerbesar(arr, SIZE));
}

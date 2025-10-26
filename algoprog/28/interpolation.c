#include <stdio.h>
const int SIZE = 8;

int interpolationSearch(int arr[], int size, int key) {
    int high = size - 1;
    int low = 0;

    while (key >= arr[low] && key <= arr[high] && low <= high) {
        int probe = low + (high - low) * (key - arr[low]) / (arr[high] - arr[low]);

        if (arr[probe] == key) {
            return probe;
        } else if (arr[probe] < key) {
            low = probe + 1;
        } else {
            high = probe - 1;
        }
    }

    return -1;
}

int main() {
    int arr[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8};

    printf("%d\n", interpolationSearch(arr, SIZE, 8));
}

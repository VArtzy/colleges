#include <stdio.h>

int main() {
    int a, b;
    float result;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b); // Kesalahan di sini

    result = (float)a / (float)b; // Potensi kesalahan lain
    printf("The division of %d and %d is %f\n", a, b, result);

    return 0;
}

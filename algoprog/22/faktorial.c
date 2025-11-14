#include <stdio.h>
int faktorial(int n) {
if (n == 1) return 1;
return n * faktorial(n - 1);
}

int main() {
    printf("%d", faktorial(5));
}

#include <stdio.h>

int binary_exponentiation(int x, int n) {
    int acc = 1;
    while (n != 0) {
        if(n % 2 == 1) {
            acc *= x;
        }
        n /= 2;
        x *= x;
    }
    return acc;
}

int main() {
    int x, n;
    scanf("%d %d", &x, &n);
    printf("%d", binary_exponentiation(x, n));
}

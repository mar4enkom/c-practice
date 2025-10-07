#include <stdio.h>

unsigned binary_exponentiation_mod(int x, int n, int k) {
    unsigned acc = 1;
    unsigned mult = x % k;
    while (n > 0) {
        if (n % 2 == 1) {
            acc = (acc * mult) % k;
        }
        mult = (mult * mult) % k;
        n /= 2;
    }
    return acc;
}

int main() {
    unsigned x, n, k;
    scanf("%d %d %d", &x, &n, &k);
    printf("%d", binary_exponentiation_mod(x, n, k));
}

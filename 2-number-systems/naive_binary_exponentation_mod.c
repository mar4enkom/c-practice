#include <stdio.h>

unsigned naive_binary_exponentation_mod(unsigned x, unsigned n, unsigned k) {
    unsigned long long mult = x % k;
    unsigned long long prod = mult;
    while (n > 1) {
        prod = (prod * mult) % k;
        n--;
    }
    return prod;
}

int main() {
    int x, n, k;
    scanf("%d %d %d", &x, &n, &k);
    printf("%d", naive_binary_exponentation_mod(x, n, k));
}
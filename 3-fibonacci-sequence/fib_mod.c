#include <stdio.h>

unsigned long long fib_mod(unsigned n, unsigned k) {
    if(n == 0) return 0;
    if(n <= 2) return 1;
    unsigned long long last = 1;
    unsigned long long cur = 1;

    for(unsigned i=3; i<=n; i++) {
        unsigned long long temp = cur;
        cur = (last + cur) % k;
        last = temp;
    }
    return cur;
}

int main() {
    unsigned n, k;
    scanf("%u %u", &n, &k);
    printf("%llu", fib_mod(n, k));
}
#include <stdio.h>

unsigned long long fib_iter(unsigned n) {
    if(n == 0) return 0;
    if(n <= 2) return 1;
    unsigned long long last = 1;
    unsigned long long cur = 1;

    for(unsigned i=3; i<=n; i++) {
        unsigned long long temp = cur;
        cur += last;
        last = temp;
    }
    return cur;
}

int main() {
    unsigned n;
    scanf("%u", &n);
    printf("%llu", fib_iter(n));
}
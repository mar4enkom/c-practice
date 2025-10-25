#include <stdio.h>

unsigned period_pisano(unsigned k) {
    if(k <= 1) return 0;
    unsigned long long last = 0;
    unsigned long long cur = 1;
    unsigned index = 0;

    while(1) {
        index++;
        unsigned temp = cur;
        cur = (last + cur) % k;
        last = temp;
        if(last == 0 && cur == 1) break;
    }

    return index;
}

unsigned fib_mod(unsigned n, unsigned k) {
    if(n == 0) return 0;
    if(n <= 2) return 1;
    unsigned last = 1;
    unsigned cur = 1;

    for(unsigned i=3; i<=n; i++) {
        unsigned temp = cur;
        cur = (last + cur) % k;
        last = temp;
    }
    return cur;
}

int main() {
    unsigned long long n;
    unsigned k;
    scanf("%llu %u", &n, &k);
    unsigned pp = period_pisano(k);
    printf("%u %u", fib_mod(n % pp, k), pp);
}
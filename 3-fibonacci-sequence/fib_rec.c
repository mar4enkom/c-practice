#include <stdio.h>

unsigned long long fib_rec(unsigned n) {
    if(n == 0) return 0;
    if(n <= 2) return 1;
    return fib_rec(n-1) + fib_rec(n-2); 
}

int main() {
    unsigned n;
    scanf("%u", &n);
    printf("%llu", fib_rec(n));
}
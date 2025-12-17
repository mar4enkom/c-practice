#include <stdio.h>

long long iabs(long long a) {
    return a < 0 ? -a : a;
}

int eu_mod(long long x, long long y) {
    long long q = x % y;
    return q < 0 ? q + iabs(y) : q;
}

int gcd(long long x, long long y) {
    int q = eu_mod(x, y);
    return q == 0 ? y : gcd(y, q);
}

int main() {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    printf("%lld", gcd(x, y));
}
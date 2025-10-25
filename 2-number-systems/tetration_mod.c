#include <stdio.h>
#include <math.h>

static unsigned long long gcd_ull(unsigned long long a, unsigned long long b) {
    while (b != 0) {
        unsigned long long t = a % b;
        a = b;
        b = t;
    }
    return a;
}

static unsigned long long phi_ull(unsigned long long n) {
    if (n == 0) return 0;
    unsigned long long result = n;
    unsigned long long x = n;
    for (unsigned long long p = 2; p * p <= x; ++p) {
        if (x % p == 0) {
            while (x % p == 0) x /= p;
            result = result / p * (p - 1);
        }
    }
    if (x > 1) {
        result = result / x * (x - 1);
    }
    return result;
}

static unsigned long long mul_mod_ull(unsigned long long a, unsigned long long b, unsigned long long mod) {
    __uint128_t prod = ( __uint128_t )a * ( __uint128_t )b;
    prod %= ( __uint128_t )mod;
    return (unsigned long long)prod;
}

unsigned long long pow_mod(
    unsigned long long x,
    unsigned long long n,
    unsigned long long k
) {
    if (k == 1) return 0;
    unsigned long long acc = 1 % k;
    unsigned long long mult = x % k;
    while (n > 0) {
        if (n & 1ULL) {
            acc = mul_mod_ull(acc, mult, k);
        }
        mult = mul_mod_ull(mult, mult, k);
        n >>= 1ULL;
    }
    return acc;
}

unsigned long long tetration(
    unsigned long long a,
    unsigned long long b,
    unsigned long long n
) {
    if (n == 1) return 0;
    if (b == 1) return a % n;
    if (a == 0) return 0;
    if (a == 1) return 1 % n;
    unsigned long long ph = phi_ull(n);
    unsigned long long e = tetration(a, b - 1, ph);
    if (gcd_ull(a, n) == 1ULL) {
        return pow_mod(a, e, n);
    } else {
        return pow_mod(a, e + ph, n);
    }
}

int main() {
    unsigned long long a, b, n;
    scanf("%llu %llu %llu", &a, &b, &n);

    if(a < 1 || b < 1 || n < 1) {
        return 255;
    }

    printf("%llu", tetration(a, b, n));
}

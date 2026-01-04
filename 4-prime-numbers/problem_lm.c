#include<stdio.h>
#include<assert.h>

unsigned long long gcd(unsigned long long a, unsigned long long b) {
    int r = a % b;
    assert(b != 0);
    if(r == 0) {
        return b;
    }
    return gcd(b, r);
}

int main() {
    unsigned long long n;
    scanf("%llu", &n);

    assert(n>=2);

    unsigned long long current_lcd=2;
    for (unsigned long long i=2; i+1<=n; ++i) {
        current_lcd = current_lcd * (i + 1) / gcd(current_lcd, i+1);
    }

    printf("%llu", current_lcd);
}
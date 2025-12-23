#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

int is_prime(int n, char *s) {
    assert(n >= 0);
    return s[n] == 0 ? 1 : 0;
}

void fill_sieve(char *s, int n) {
    for (int i=2; i*i < n; ++i) {
        if (s[i]) continue;
        for (int j=i*i; j < n; j+=i) {
            s[j] = 1;
        }
    }
}

int calc_digits(int n) {
    int count = 0;

    while (n != 0) {
        n /= 10;
        count++;
    }

    return count;
}

int ipow10(int k) {
    int p = 1;
    while (k--) p *= 10;
    return p;
}

int shift(int n) {
    int k = calc_digits(n);
    int p = ipow10(k - 1);
    return 10 * (n % p) + n / p;
}

char is_prime_circular(unsigned a, char *s) {
    if (!is_prime(a, s)) return 0;
    int a_digits = calc_digits(a);

    for (int i=1;i<calc_digits(a); ++i) {
        a = shift(a);
        if (!is_prime(a, s) || calc_digits(a) != a_digits) return 0;
    }
    return 1;
}

int main() {
    int N;
    scanf("%d", &N);

    if(N <= 2) {
        printf("2");
    }

    char *s = calloc(N*10, sizeof(char));
    fill_sieve(s, N*10);

    for (int i=0; ; ++i) {
        if(is_prime_circular(N-i, s)) {
            printf("%d", N-i);
            break;
        }

        if(is_prime_circular(N+i, s)) {
            printf("%d", N+i);
            break;
        }
    }

    free(s);
}
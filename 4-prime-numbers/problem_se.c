#include<stdio.h>
#include<stdlib.h>

void fill_eratosthenes_sieve(char *sieve, unsigned n) {
    sieve[0] = '0';
    for (int i=2; i*i <= n; i++) {
        for (int j=i*i; j<=n; j+=i) {
            sieve[j-1] = '1';
        }
    }
}

void count_primes_up_to(unsigned n) { 
    char *sieve = calloc(sizeof(char), n);

    fill_eratosthenes_sieve(sieve, n);

    unsigned res = 0;
    for (int i=0; i<n; i++) {
        if(!sieve[i]) {
            res++;
        }
    }
    printf("%u", res);

    free(sieve);
}

int main() {
    unsigned n;
    scanf("%u", &n);
    count_primes_up_to(n);
}
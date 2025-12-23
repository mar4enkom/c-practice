#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include "u_template.h"

void fill_sieve(struct sieve_t *sv) {
    for (int i=2; i*i < sv->n; ++i) {
        if (sv->s[i]) continue;
        for (int j=i*i; j < sv->n; j+=i) {
            sv->s[j] = 1;
        }
    }
}

int is_prime(int n, struct sieve_t *sv) {
    assert(sv->n >= n);
    return sv->s[n] == 0 ? 1 : 0;
}

int nth_prime(struct sieve_t *sv, int N) {
    int r = N;
    for (int i=2; i<sv->n; ++i) {
        if (is_prime(i, sv) == 1) {
            r--;
            if (r == 0) return i;
        }
    }
    return -1;
}

int main() {
    struct sieve_t sv = {
        .n = 1000,
        .s = calloc(1000, sizeof(char))
    };

    for (int i=0; i<= sv.n; ++i) {
        sv.s[i] = 0;
    }

    fill_sieve(&sv);
    printf("%d", nth_prime(&sv, 50));
    free(sv.s);
}

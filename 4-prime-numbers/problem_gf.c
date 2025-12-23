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

int calc(int a, int b, int n) {
    return n*n+a*n+b;
}

int main() {
    int N;
    scanf("%u", &N);

    int sieve_size = calc(N-1, N-1, 100);
    char *s = calloc(sieve_size, sizeof(char));
    fill_sieve(s, sieve_size);

    int n_max = 0, a_res, b_res;
    int a_start = -N+1;

    for (int b=2; b<N; ++b) {
        if (!is_prime(b, s)) continue;
        for (int a=a_start; a<N; ++a) {
            for (int n=0; ;++n) {
                int res = calc(a, b, n);
                if(res < 0 || !is_prime(res, s)) {
                    if(n > n_max) {
                        n_max = n;
                        a_res = a;
                        b_res = b;
                    }
                    break;
                }
            }
        }
    }
    printf("%d %d %d", a_res, b_res, n_max);

    free(s);
}
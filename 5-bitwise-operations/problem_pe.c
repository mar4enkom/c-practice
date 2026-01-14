#include<stdio.h>
#include<stdlib.h>

struct sieve_t {
  int n;
  unsigned char *s;
};

unsigned char set_n_bit(unsigned char num, unsigned char n) {
  unsigned char mask = 1 << n;
  return num | mask;
}

unsigned char n_bit(unsigned char num, unsigned char n) {
  return (num >> n) & 1;
}

void fill_sieve(struct sieve_t *sv) {
  int n_bits = sv->n*8;
  for (int i=2; i*i<n_bits; ++i) {
    if (n_bit(sv->s[i/8], i%8)) continue;
    for (int j=i*i; j<n_bits; j+=i) {
      sv->s[j/8] = set_n_bit(sv->s[j/8], j%8);
    }
  }
}

int is_prime(struct sieve_t *sv, unsigned n) {
  return n_bit(sv->s[n/8], n%8) == 0;
}

int main() {
    int N = 1000;
    struct sieve_t sv = {
        .n = N,
        .s = calloc(N, sizeof(char))
    };

    if (!sv.s) return 255;

    fill_sieve(&sv);

    free(sv.s);
}

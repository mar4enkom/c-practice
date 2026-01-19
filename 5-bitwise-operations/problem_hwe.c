#include<stdio.h>
#include<stdlib.h>

struct sieve_t {
    int n;
    unsigned char *mod1;
    unsigned char *mod5;  
};  

unsigned char set_n_bit(unsigned char num, unsigned char n) {
  unsigned char mask = 1 << n;
  return num | mask;
}

unsigned char n_bit(unsigned char num, unsigned char n) {
  return (num >> n) & 1;
}

void fill_sieve(struct sieve_t *sv) {
  unsigned long long n_bits = sv->n*8;

  unsigned total_bit_num, byte_num;
  for (unsigned long long i=5; i*i<n_bits*6; i+=(i%6==5 ? 2 : 4)) {
    for (unsigned long long j=i*i; j<=n_bits*6; j+=(i*6)) {
      total_bit_num = j / 6;
      byte_num = total_bit_num / 8;
      sv->mod1[byte_num] = set_n_bit(sv->mod1[byte_num], total_bit_num%8);
    }
  }

  for (unsigned long long i=5; i*7<n_bits*6; i+=6) {
    for (unsigned long long j=i*7; j<=n_bits*6; j+=(i*6)) {
      total_bit_num = j / 6;
      byte_num = total_bit_num / 8;
      sv->mod5[byte_num] = set_n_bit(sv->mod5[byte_num], total_bit_num%8);
    }
  }
}

int is_prime(struct sieve_t *sv, unsigned n) {
  unsigned total_bit_num = n / 6;
  unsigned byte_num = total_bit_num / 8;

  if (n <= 3) {
    return 1;
  }
  if (n%2 == 0 || n%3 == 0) {
    return 0;
  }

  if ((n-1)%6 == 0) {
    return n_bit(sv->mod1[byte_num], total_bit_num%8) == 0;
  } else {
    return n_bit(sv->mod5[byte_num], total_bit_num%8) == 0;
  }
}

int main() {
    int N = 104857600;
    struct sieve_t sv = {
        .n = N,
        .mod1 = calloc(N, sizeof(char)),
        .mod5 = calloc(N, sizeof(char))
    };

    if (!sv.mod1 || !sv.mod5) return 255;

    fill_sieve(&sv);

    unsigned a;
    while(1) {
      scanf("%u", &a);
      printf("%u \n", is_prime(&sv, a));
    }

    free(sv.mod1);
    free(sv.mod5);
}

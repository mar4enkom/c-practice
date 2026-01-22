#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

unsigned long long pow_mod(
    unsigned long long x, 
    unsigned long long n, 
    unsigned long long k
) {
    unsigned long long acc = 1;
    unsigned long long mult = x % k;
    while (n > 0) {
        if (n % 2 == 1) {
            acc = (acc * mult % k) % k;
        }
        mult = (mult * mult) % k;
        n /= 2;
    }
    return acc;
}

unsigned long long gcd(
    unsigned long long x, 
    unsigned long long y
) {        
  unsigned long long q;

  if(y > x) {
    unsigned long long temp = y;
    y = x;
    x = temp;
  }
  assert (y > 0);
  q = x % y;

  while (q != 0) {
    x = y;
    y = q;
    q = x % y;
  }
  return y;
}

char is_prime(unsigned long long p) {
    unsigned counter = 0;
    unsigned long long n=5;
    srand(time(NULL));

    while(counter < 100) {
        n = rand() % p;
        if (gcd(n, p) != 1) continue;
        counter++;
        if (pow_mod(n%p, p-1, p) != 1) return 0;
    }
    return 1;
}

int main() {
    unsigned long long p;
    scanf("%llu", &p);
    printf("%d", is_prime(p));
}
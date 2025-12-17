#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

int iabs(int a) {
    return a < 0 ? -a : a;
}

int eu_mod(int x, int y) {
    int q = x % y;
    return q < 0 ? q + iabs(y) : q;
}

unsigned long long gcd(unsigned long long x, 
                       unsigned long long y) {        
  unsigned long long q;

  if(y > x) {
    unsigned long long temp = y;
    y = x;
    x = temp;
  }
  assert (y > 0);
  q = eu_mod(x, y);

  while (q != 0) {
    x = y;
    y = q;
    q = eu_mod(x, y);
  }
  return y;
}

int main() {
  unsigned long long x = 0, y = 0, g;

  int res;
  
  res = scanf("%llu %llu", &x, &y);
  assert(res == 2);
  g = gcd(x, y);
  printf("%llu %llu", x, y);
  return 0;
}
#include <stdio.h>
#include <assert.h>

long long iabs(long long a) {
    return a < 0 ? -a : a;
}

long long eu_mod(long long x, long long y) {
    long long r = x % y;
    return r < 0 ? r + iabs(y) : r;
}

long long gcd(long long x, long long y) {
    long long r = eu_mod(x, y);
    return r == 0 ? y : gcd(y, r);
}

void extended_euclid(
    long long x,
    long long y
) {
  long long r, q, u, u_old, v, v_old;

  if(y > x) {
    long long temp = y;
    y = x;
    x = temp;
    u = 1;
    v = 0;
    u_old = 0;
    v_old = 1;
  } else {
    u = 0;
    v = 1;
    u_old = 1;
    v_old = 0;
  }

  do {
    r = eu_mod(x, y);
    q = (x-r) / y;
    x = y;
    y = r;
    long long u_temp = u, v_temp = v; 
    u = u_old - q * u;
    v = v_old - q * v;
    u_old = u_temp;
    v_old = v_temp;
  } while (r != 0);
  
  printf("%lld %lld %lld", u_old, v_old, x);
}

int main() {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    extended_euclid(x,y);
    return 0;
}
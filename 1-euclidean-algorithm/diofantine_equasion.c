#include <stdio.h>
#include <assert.h>

int iabs(int a) {
    return a < 0 ? -a : a;
}

int eu_mod(int x, int y) { 
    int r = x % y; 
    return r < 0 ? r + iabs(y) : r; 
}

void diofantine_equasion(int x, int y, int c) {
  int r, q, u = 0, u_old = 1, v = 1, v_old = 0;

  do {
    r = eu_mod(x, y);
    q = (x-r) / y;
    x = y;
    y = r;
    int u_temp = u, v_temp = v; 
    u = u_old - q * u;
    v = v_old - q * v;
    u_old = u_temp;
    v_old = v_temp;
  } while (r != 0);

  int d = iabs(x);
  if (c % d != 0) {
    printf("NONE");
    return;
  }
  
  int k = c / d;
  int A = u_old * k;
  int B = v_old * k;
  if (x < 0) {
    A = -A;
    B = -B;
  }

  printf("%d %d", A, B);
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    diofantine_equasion(a, b, c);
}
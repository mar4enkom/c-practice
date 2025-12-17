#include<stdio.h>

long long iabs(long long x) {
    return x < 0 ? -x : x;
}

long long eu_mod(long long x, long long y) {
    long long rem = x % y; 
    return rem < 0 ? rem + iabs(y) : rem; 
}

long long eu_div(long long x, long long y) {
    return (x - eu_mod(x,y)) / y; 
}

void continued_fractions(long long x, long long y) {
    long long r, q;
    for(int i=0; ; i++) {
        r = eu_mod(x, y);
        q = eu_div(x, y);
        x = y;
        y = r;
        
        if(r == 0) {
            printf("%lld", q);
            break;
        } else {
            printf("%lld ", q);
        }
    }
}

int main() {
    long long x, y;
    scanf("%lld %lld", &x, &y);
    continued_fractions(x, y);
}
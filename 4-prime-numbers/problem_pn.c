#include<stdio.h>

char is_prime(unsigned a) {
    if(a < 2) return '0';
    for(unsigned num = 2; num <= a / num; num++) {
        if(a % num == 0) {
            return '0';
        }
    }
    return '1';
}

void nth_prime(unsigned a) {
    unsigned n = 0;

    for (unsigned i=1; i<=4294967295; i++) {
        if(is_prime(i) == '1') {
            n++;
        }
        if(a == n) {
            printf("%u", i);
            return;
        }
    }
}

int main() {
    unsigned a;
    scanf("%u", &a);
    nth_prime(a);
}
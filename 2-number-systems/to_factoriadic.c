#include <stdio.h>

void to_factoriadic(unsigned x) {
    if(x == 0) {
        printf("%u.", 0);
    }

    int factorials[32] = {0, 1};

    for (int i = 1; ; i++) {
        unsigned nextFactorial = factorials[i] * (i + 1);
        if (nextFactorial >= x) {
            break;
        }
        factorials[i+1] = nextFactorial;
    }

    unsigned remainder = x;
    for (int i = 31; i >= 0; i--) {
        if(factorials[i] == 0) {
            continue;
        }
        printf("%u", remainder / factorials[i]);
        printf(".");
        remainder = x % factorials[i];
    }
}

int main() {
    unsigned x;
    scanf("%u", &x);
    to_factoriadic(x);
}
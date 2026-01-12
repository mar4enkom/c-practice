#include<stdio.h>
#include<stdlib.h>

unsigned char invert_n_bit(unsigned char num, unsigned char n) {
    unsigned char mask = 1 << n;
    return num ^ mask;
}

int main() {
    unsigned n;
    scanf("%u", &n);
    unsigned char *bytes = calloc(n, sizeof(char));

    if (!bytes) {
        return 255;
    }

    for (int i=0; i<n; ++i) {
        scanf(" %hhu", &bytes[i]);
    }

    char k;
    scanf(" %hhu", &k);

    int n_byte = k/8;
    for (int i=0; i<n; ++i) {
        if (i == n_byte) {
            printf("%d ", invert_n_bit(bytes[i], k%8));
        } else {
            printf("%d ", bytes[i]);
        }
    }
    
    free(bytes);
}

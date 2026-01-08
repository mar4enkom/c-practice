#include<stdio.h>

int main() {
    unsigned n;
    scanf("%d", &n);

    if (n == 0) {
        printf("NO");
        return 0;
    }

    unsigned char msb = 0, lsb = 0;
    char lsb_found = 0;

    for (int i = 0; i < sizeof(n)*8; ++i) {
        if((n >> i) & 1u) {
            msb = i;
            if (!lsb_found) {
                lsb_found = 1;
                lsb = i;
            }
        }
    }
    
    printf("%u %u", msb, lsb);
}
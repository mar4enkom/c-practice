#include <stdio.h>

void to_base_n(unsigned x, unsigned y) {
    unsigned arr[32] = {};
    int ind = 0;

    while (x != 0) {
        arr[ind] = x % y;
        x /= y;
        ind++;
    }


    int started = 0;
    for (int i = 31; i >= 0; i--) {
        if(arr[i] == 0 && started == 0) {
            continue;
        }
        started = 1;
        printf("%u", arr[i]);
    }
}

int main() {
    unsigned x, y;
    scanf("%u %u", &x, &y);
    convert_to_base(x, y);
}
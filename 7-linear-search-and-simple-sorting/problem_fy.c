#include<stdio.h>

int myrand() {
  static unsigned long int seed = 1;
  seed = seed * 1103515245 + 12345;
  return (unsigned int)(seed / 65536) % 32768;
}

int main() {
    unsigned n; 
    scanf("%u", &n);

    if(n == 0) {
        printf("0");
    }

    int arr[n];

    for (int i=0; i<n; ++i) {
        scanf("%d", &arr[i]);
    }

    for (int i=n-1; i>=0; --i) {
        int p = myrand()%(i+1);
        int temp = arr[i];
        arr[i] = arr[p];
        arr[p] = temp;
    }

    for (int i=0; i<n; ++i) {
        printf("%d ", arr[i]);
    }
}
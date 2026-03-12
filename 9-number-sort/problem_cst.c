#include<stdio.h>
#include<limits.h>

int max_elem(int *arr, int n) {
    int max=arr[0];
    for (int i=1; i<n; ++i) {
        if(arr[i]>max) {
            max=arr[i];
        }
    }
    return max;
}

int main() {
    unsigned n; 
    scanf("%u", &n);
    int arr[n];

    for (int i=0; i<n; ++i) {
        scanf("%d", &arr[i]);
    }

    int max = max_elem(arr, n);
    int m = max+1;
    int counts[m];

    for (int i=0; i<m; ++i) {
        counts[i] = 0;
    }

    for (int i=0; i<n; ++i) {
        int current = arr[i];
        counts[current]++;
    }

    for (int i=0; i<m; ++i) {
        printf("%d ", counts[i]);
    }
}
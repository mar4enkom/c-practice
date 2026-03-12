#include<stdio.h>

typedef int (*cmp_t)(const void *lhs, const void *rhs);

int compare_ints(const void * lhs, const void * rhs) {
    const int ilhs = *(const int *) lhs;
    const int irhs = *(const int *) rhs;
    if (ilhs < irhs) {
        return -1;
    } else if (ilhs > irhs) {
        return 1;
    }
    return 0;
}

void *cbsearch(const void *key, const void *base, int num, int size, cmp_t cmp) {
    int l = 0, r = num - 1;
    unsigned char * arr = (unsigned char *) base; 
    while (l <= r) {
        int mid = (l + r) / 2;
        void * curr = arr+mid*size;
        int c = cmp(key, curr); 
        if (c < 0) r = mid - 1;
        else if (c > 0) l = mid + 1;
        else return curr;
    }
    return NULL;
}

int main() {
    int key = 1; 
    // scanf("%d", &n);
    int arr[10] = {1,2,3,4,5, 100, 999, 1000, 10001, 1000000};

    // for (int i=0; i<n; ++i) {
    //     scanf("%d", &arr[i]);
    // }

    int res = *(int *)cbsearch(&key, arr, 10, sizeof(int), compare_ints);
    printf("%d ", res);
}
#include<stdio.h>

typedef int (*cmp_t)(void const * lhs, void const * rhs);

int compare_ints(const void * lhs, const void * rhs) {
    const int ilhs = *(const int *) lhs;
    const int irhs = *(const int *) rhs;
    if (ilhs < irhs) {
        return 1;
    }
    return 0;
}

void *find_min(void * parr, int eltsize, int numelts, cmp_t cmp) {
    unsigned char * arr = (unsigned char *) parr;
    void *min = arr;

    for (int i=1; i<numelts; ++i) {
        void * curr = arr+i*eltsize;
        if (cmp(curr, min) == 1) {
            min = curr;
        }     
    }
    return min;
}

void swap(void *a, void *b, size_t eltsize) {
    unsigned char *pa = (unsigned char *)a;
    unsigned char *pb = (unsigned char *)b;

    for (size_t i = 0; i < eltsize; ++i) {
        unsigned char tmp = pa[i];
        pa[i] = pb[i];
        pb[i] = tmp;
    }
}

int selstep(void * parr, int eltsize, int numelts, int nsorted, cmp_t cmp) {
    unsigned char * arr = (unsigned char *) parr;

    void *start = arr+nsorted*eltsize;
    int *min = find_min(start, eltsize, numelts-nsorted, cmp);
    swap(start, min, eltsize);
    return 0;
}

void selsort(void * parr, int eltsize, int numelts, int nsorted, cmp_t cmp) {
    for (int i=nsorted; i<numelts; ++i) {
        selstep(parr, eltsize, numelts, i, cmp);
    }
}

int main() {
    int n, nsorted; 
    scanf("%u", &n);
    int arr[n];

    for (int i=0; i<n; ++i) {
        scanf("%d", &arr[i]);
    }

    scanf("%u", &nsorted);

    selsort(arr, sizeof(int), n, nsorted, compare_ints);
    for (int i=0; i<n; ++i) {
      printf("%d ", arr[i]);
    }
}
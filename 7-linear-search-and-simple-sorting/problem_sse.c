#include<stdio.h>

void ssort_1(int *arr, int len, int pos) {
  int min = arr[pos];
  int min_ind = pos;
  for (int i = pos; i < len; ++i) {
    if (arr[i] < min) {
        min = arr[i];
        min_ind = i;
    }
  }
  if (min_ind != pos) {
    arr[min_ind] = arr[pos];
    arr[pos] = min;
  }
}

int main() {
    unsigned n, pos; 
    scanf("%u", &n);
    int arr[n];

    for (int i=0; i<n; ++i) {
        scanf("%d", &arr[i]);
    }

    scanf("%u", &pos);

    ssort_1(arr, n, pos);
    for (int i=0; i<n; ++i) {
      printf("%d ", arr[i]);
    }
}
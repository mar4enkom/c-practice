#include<stdio.h>

int moveright(int *arr, int key, int last) {
  while (arr[--last] > key) {
    arr[last+1] = arr[last]; 
  }
  return last+1;
}

void inssort(int *arr, int len) {
  int i;
  for (i = 0; i < len; ++i) {
    int key, pos;
    key = arr[i];
    pos = moveright(arr, key, i);
    arr[pos] = key;
  }
}

int main() {
    unsigned n; 
    scanf("%u", &n);
    int arr[n];

    for (int i=0; i<n; ++i) {
        scanf("%d", &arr[i]);
    }

    inssort(arr, n);
    for (int i=0; i<n; ++i) {
      printf("%d ", arr[i]);
    }
}
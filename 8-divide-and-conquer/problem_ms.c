#include<stdio.h>

void merge(int *arr, int l, int m, int r) {
    int res[r+1];
    int l_index = l;
    int r_index = m + 1;
    int i = l;

    while (1) {
        if (l_index > m && r_index <= r) {
            res[i] = arr[r_index];
            r_index++;
        } else if (r_index > r && l_index <= m) {
            res[i] = arr[l_index];
            l_index++;
        } else if (l_index <= m && arr[l_index] <= arr[r_index]) {
            res[i] = arr[l_index];
            l_index++;
        } else if (r_index <= r && arr[r_index] < arr[l_index]) {
            res[i] = arr[r_index];
            r_index++;
        } else {
            break;
        }
        ++i;
    }

    for (int i=l; i<=r; ++i) {
        arr[i] = res[i];
    }
}

int main() {
  int arr[] = { 8, 9, 9, 10, 11, 7, 9, 9, 11, 18  };
  merge(arr, 0, 4, 9);
  
  //   int arr[] = { 2, 1, 3 };
  // int res = partition(arr, 0, 2);

  // int arr[] = { 6, 1, 9, 3, 2, 10, 8, 7, 4 };
  // int res = partition(arr, 0, 8);

  //printf("res: %d \n", res);
  for (int i=0; i<=9; ++i) {
    printf("%d ", arr[i]);
  }
}

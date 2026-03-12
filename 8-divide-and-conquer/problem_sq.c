#include<stdio.h>

// void qsort_impl(int *arr, unsigned low, unsigned high) {
//   if (low >= high) return;
//   unsigned pi = partition(arr, low, high);
//   if (pi > low) qsort_impl(arr, low, pi - 1);
//   qsort_impl(arr, pi + 1, high);
// }

// void qsort(int *arr, unsigned len) { qsort_impl(arr, 0u, len - 1); }

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

unsigned partition(int *arr, unsigned low, unsigned high) {
  int *pivot = &arr[low];
  low++;

  while (low < high) {
    char left_ready = *pivot < arr[low];
    char right_ready = *pivot >= arr[high];
    if (left_ready && right_ready) {
      swap(&arr[low], &arr[high]);
      low++;
      high--;
      continue;
    }

    if (!left_ready) {
      low++;
    }

    if (!right_ready) {
      high--;
    }
  }

  if (low == high && *pivot < arr[high]) {
    swap(pivot, &arr[high-1]);
    return high-1;
  }

  if (arr[low] == arr[high]) {
    swap(pivot, &arr[low]);
    return low;
  }

  swap(pivot, &arr[high]);
  return high;
}

int main() {
  int arr[] = { 1, 1, 1 };
  int res = partition(arr, 0, 2);
  
  // int arr[] = { 2, 1, 3 };
  // int res = partition(arr, 0, 2);

  // int arr[] = { 6, 1, 9, 3, 2, 10, 8, 7, 4 };
  // int res = partition(arr, 0, 8);

  printf("res: %d \n", res);
  for (int i=0; i<=2; ++i) {
    printf("%d ", arr[i]);
  }
}

/* ---------
Bubble Sort
------------ */

#include <stdio.h>

// swap function
// dereferencing pointer with *phigh, which gets the value of the int pointed to below
void swap(int *phigh, int *plow) {
  int temp = *phigh;
  *phigh = *plow;
  *plow = temp;
}

// pointers used when calling swap function below
// &arr[y] points to the address in memory of the current int in question
int main() {
  int arr[] = { 
    18, 77, 4, 666, 92, 33, 2, 42, 39, 14, 
    60, 34, 66, 1, 919, 6, 9, 75, 99, 31, 55, 
    16, 455, 7, 334, 235, 23, 19, 423, 16 
  };

  int size = sizeof(arr)/sizeof(arr[0]);

  int left, right;
  for (x = 0; x < size - 1; x++) {
    for (y = 0; y < size - x - 1; y++) {
      if (arr[y] > arr[y + 1]) {
        swap(&arr[y], &arr[y + 1]);
      }
    }
  }

  printf("Sorted array:\n");

  for (int z = 0; z < size; z++) {
    if (z == 0) {
      printf("[%d, ", arr[z]);
    } else if (z == size - 1) {
      printf("%d]\n", arr[z]);
    } else {
      printf("%d, ", arr[z]);
    }
  }
  return 0;
}
/* ---------
Selection Sort
------------ */

#include <stdio.h>

void swap(int *phigh, int *plow) {
  int temp = *phigh;
  *phigh = *plow;
  *plow = temp;
}

void select(int arr[], int size) {
  int i, j, min;

  for (i = 0; i < size - 1; i++) {
    min = i;
    for (j = i + 1; j < size; j++) {
      if (arr[j] < arr[min]) {
        min = j;
      }
      swap(&arr[min], &arr[i]);
    }
  }
}

void prettyPrint(int *size, int arr[]) {
  for (int i = 0; i < *size; i++) {
    if (i == 0) {
      printf("[%d, ", arr[i]);
    } else if (i == *size - 1) {
      printf("%d]\n", arr[i]);
    } else {
      printf("%d, ", arr[i]);
    }
  }
}

int main() {
  int arr[] = { 
    18, 77, 4, 666, 92, 33, 2, 42, 39, 14, 
    60, 34, 66, 1, 919, 6, 9, 75, 99, 31, 55, 
    16, 455, 7, 334, 235, 23, 19, 423, 16 
  };

  int size = sizeof(arr)/sizeof(arr[0]);

  printf("\nArray:\n");
  prettyPrint(&size, arr);

  printf("\nSelecting...\n");
  select(arr, size);

  printf("\nSorted array:\n");
  prettyPrint(&size, arr);

  return 0;
}
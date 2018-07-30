/* ---------
Insertion Sort
------------ */

#include <stdio.h>

void insert(int arr[], int size) {
  int i, key, j;
  for (i = 1; i < size; i++) {
    key = arr[i];
    j = i - 1;

    while (j >= 0 && arr[j] > key) {
      arr[j + 1] = arr[j];
      j--;
    }
    arr[j + 1] = key;
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

  printf("\nInserting...\n");
  insert(arr, size);

  printf("\nSorted array:\n");
  prettyPrint(&size, arr);

  return 0;
}
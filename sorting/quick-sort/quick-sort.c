/* ---------
Quick Sort
------------ */

#include <stdio.h>

int arr[] = { 
    18, 77, 4, 666, 92, 33, 2, 42, 39, 14, 
    60, 34, 66, 1, 919, 6, 9, 75, 99, 31, 55, 
    16, 455, 7, 334, 235, 23, 19, 423, 16 
};

void swap(int *phigh, int *plow) {
  int temp = *phigh;
  *phigh = *plow;
  *plow = temp;
}


int partition(int left, int right) {
  int pivot = arr[right];
  int i = (left - 1);

  for (int j = left; j <= right - 1; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], &arr[right]);
  return (i + 1);
}

void quickSort(int left, int right) {
  if (left < right) {
    int index = partition(left, right);
    quickSort(left, index - 1);
    quickSort(index + 1, right);
  }
}

void prettyPrint(int *size) {
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
  int size = sizeof(arr)/sizeof(arr[0]);

  printf("\nArray:\n");
  prettyPrint(&size);

  printf("\nQuickly sorting...\n");
  quickSort(0, size - 1);

  printf("\nSorted array:\n");
  prettyPrint(&size);

  return 0;
}
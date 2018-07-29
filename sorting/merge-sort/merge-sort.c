/* ---------
Merge Sort
------------ */

#include <stdio.h>

int arr[] = { 
    18, 77, 4, 666, 92, 33, 2, 42, 39, 14, 
    60, 34, 66, 1, 919, 6, 9, 75, 99, 31, 55, 
    16, 455, 7, 334, 235, 23, 19, 423, 16 
};
int temp[29];

void merge(int low, int mid, int high) {
  int x, y, z;

  for (x = low, y = mid + 1, z = low; x <= mid && y <= high; z++) {
    if (arr[x] <= arr[y]) {
      temp[z] = arr[x++];
    } else {
      temp[z] = arr[y++];
    }
  }

  while (x <= mid) {
    temp[z++] = arr[x++];
  }

  while (y <= high) {
    temp[z++] = arr[y++];
  }

  for (z = low; z <= high; z++) {
    arr[z] = temp[z];
  }
}

void mergeSort(int low, int high) {
  int mid;

  if (low < high) {
    mid = (low + high) / 2;
    mergeSort(low, mid);
    mergeSort(mid + 1, high);
    merge(low, mid, high);
  } else {
    return;
  }
}

void prettyPrint(int size) {
  for (int i = 0; i < size; i++) {
    if (i == 0) {
      printf("[%d, ", arr[i]);
    } else if (i == size - 1) {
      printf("%d]\n", arr[i]);
    } else {
      printf("%d, ", arr[i]);
    }
  }
}

int main() {
  int size = sizeof(arr)/sizeof(arr[0]);

  printf("\nArray:\n");
  prettyPrint(size);

  printf("\nMerging...\n");
  mergeSort(0, size - 1);

  printf("\nSorted array:\n");
  prettyPrint(size);

  return 0;
}
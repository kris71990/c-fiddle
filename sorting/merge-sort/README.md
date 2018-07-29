# Merge Sort

Merge sort is a sorting algorithm that implements the 'divide and conquer technique'. It splits the array in half recursively until it has an array of sorted single values, known as sublists. It will then merge these sublists together by comparing values until a single array has been reconstructed.

Merge sort is a very efficient sorting algorithm, with an average and worst-case time complexity of O(n lg n). It does not however sort in place, yielding a space complexity of O(n).

## To Use
```
To compile: `clang -o merge-sort.out merge-sort.c`

To run: `./merge-sort.out`
```
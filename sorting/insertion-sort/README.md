# Insertion Sort

Insertion sort is a straightforward sorting algorithm. It iterates through an array while incrementally creating a sorted array in place behind the iteration. Each value is compared to values in the sorted array and inserted in the appropriate place.

Insertion sort can be efficient on small sets but is very inefficient on large ones. It sorts in place for an ideal space complexity of O(1), but has an average and worst case time complexity of O(n^2).

## To Use
```
To compile: `clang -o insertion-sort.out insertion-sort.c`

To run: `./insertion-sort.out`
```
# Quick Sort

Quick sort is a very efficient sorting algorithm, comparable to merge sort, but often performs even better than merge sort. It employs the 'divide and conquer' technique, splitting the array into sub-arrays and recursively sorting the sub-arrays.

The algorithm partitions the array by selecting a pivot, which can be any element (the efficiency of the algorithm depends on which element is selected; in this case, the last element is always selected - not the most efficient, but also not the least efficient implementation). The partition reorders elements so that all values greater than the pivot value or placed to the right, and all values less than the pivot are placed to the left. The algorithm then recursively continues this process until the array is sorted.

Quick sort runs in 0(n lg(n)) time and O(lg n) space.

## To Use
```
To compile: `clang -o quick-sort.out quick-sort.c`

To run: `./quick-sort.out`
```
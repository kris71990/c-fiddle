# Sudoku Solver

This program solves Sudoku puzzles via a brute-force approach. It iterates through the puzzle, finds an empty square, and recursively tries numbers on new and previous squares until the puzzle is solved.

An equivalent python version of the solver is also included to guage performance differences between the two languages - the C++ version performs significantly better in terms of execution time (20-30x faster).

## Getting Started

To compile: `g++ -o solver.out solver.cpp`

To run: `./solver.out`
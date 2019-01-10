#include <iostream>
#include <ctime>

#define GRID_FULL std::make_pair(9, 9)

double time_diff(clock_t start, clock_t end) {
  double diff = end - start;
  double diffms = (diff) / (CLOCKS_PER_SEC / 1000);
  return diffms;
}

int count;

int print_grid(int grid[][9]) {
  for (int i = 0; i < 9; i++) {
    std::cout << "\n";
    std::cout << "-------------------------------------\n";
    for (int j = 0; j < 9; j++) {
      std::cout << " ";
      if (grid[i][j] == 0) {
        std::cout << " ";
      } else {
        std::cout << grid[i][j];
      }
      std::cout << " |";
    }
  }
  std::cout << "\n-------------------------------------\n\n";
  return 0;
}

// check if valid in row
bool exists_in_row(int grid[][9], const int& row, const int& num) {
  for (int col = 0; col < 9; col++) {
    if (grid[row][col] == num) {
      return true;
    }
  }
  return false;
}

// check if valid in column
bool exists_in_column(int grid[][9], const int& col, const int& num) {
  for (int row = 0; row < 9; row++) {
    if (grid[row][col] == num) {
      return true;
    }
  }
  return false;
}

// check if valid in square
bool exists_in_box(int grid[][9], const int& box_start_row, const int& box_start_col, const int& num) {
  for (int row = 0; row < 3; row++) {
    for (int col = 0; col < 3; col++) {
      if (grid[row + box_start_row][col + box_start_col] == num) {
        return true;
      }
    }
  }
  return false;
}

// check if possible placement by validating with above functions
bool validate_placement(int grid[][9], const int& row, const int& col, const int& num) {
  bool in_row = exists_in_row(grid, row, num);
  bool in_col = exists_in_column(grid, col, num);
  bool in_box = exists_in_box(grid, row - row % 3, col - col % 3, num);
  
  return !in_row && !in_col && !in_box;
}

std::pair<int, int> get_unassigned_location(int grid[][9]) {
  for (int row = 0; row < 9; row++) {
    for (int col = 0; col < 9; col++) {
      if (grid[row][col] == 0) {
        return std::make_pair(row, col);
      }
    }
  }
  return GRID_FULL;
}

bool solve_soduko(int grid[][9]) {
  if (GRID_FULL == get_unassigned_location(grid)) {
    return true; 
  }

  std::pair<int, int> row_and_col = get_unassigned_location(grid);
  int row = row_and_col.first;
  int col = row_and_col.second;
  
  for (int num = 1; num <= 9; num++) {
    if (validate_placement(grid, row, col, num)) {
      grid[row][col] = num;
      count++;
      std::cout << "Trying again - (" << count << " guesses)\n";
      
      if (solve_soduko(grid)) {
        return true;
      }
      grid[row][col] = 0;
    }
  }
  return false; 
}

int main() {
  clock_t start = clock();
  std::cout << "\n************************************\n----------- Solve Sudoku -----------\n************************************\n";

  int grid[9][9] = { 
    { 0, 9, 0, 0, 0, 0, 8, 5, 3 },
    { 0, 0, 0, 8, 0, 0, 0, 0, 4 },
    { 0, 0, 8, 2, 0, 3, 0, 6, 9 },
    { 5, 7, 4, 0, 0, 2, 0, 0, 0 },
    { 0, 0, 0, 0, 0, 0, 0, 0, 0 },
    { 0, 0, 0, 9, 0, 0, 6, 3, 7 },
    { 9, 4, 0, 1, 0, 8, 5, 0, 0 },
    { 7, 0, 0, 0, 0, 6, 0, 0, 0 },
    { 6, 8, 2, 0, 0, 0, 0, 9, 0 },
  };

  print_grid(grid);

  if (solve_soduko(grid) == true) {
    clock_t end = clock();
    double elapsed_timems = time_diff(start, end);
    double elapsed_time = elapsed_timems / 1000.0;
    std::cout << "\nSolution Found in " << elapsed_time << " seconds (" << elapsed_timems << " milliseconds).\n";
    print_grid(grid);
  } else {
    clock_t end = clock();
    std::cout << "No solution exists.\n\n";
  }
  
  return 0;
}
#define GRID_FULL std::make_pair(9, 9)

count = 0

def print_grid(grid):
  for x in range(9):
    print('\n');
    print('-------------------------------------\n');
    for j in range(9):
      print(' ')
      if (grid[i][j] == 0):
        print(' ')
      else:
        print(' ') << grid[i][j]
      print() << " |";
  print('\n-------------------------------------\n\n')

# check if valid in row
def exists_in_row(grid, row, num):
  for col in range(9):
    if (grid[row][col] == num):
      return true;
  return false;

# check if valid in column
def exists_in_column(grid, col, num):
  for row in range(9):
    if (grid[row][col] == num):
      return true;
  return false;

# check if valid in square
def exists_in_box(grid, box_start_row, box_start_col, num):
  for row in range(3):
    for col in range(3):
      if (grid[row + box_start_row][col + box_start_col] == num):
        return true;
  return false;

# check if possible placement by validating with above functions
def validate_placement(grid, row, col, num):
  in_row = exists_in_row(grid, row, num)
  in_col = exists_in_column(grid, col, num)
  in_box = exists_in_box(grid, row - row % 3, col - col % 3, num)
  # return !in_row and !in_col and !in_box

# std::pair<int, int> get_unassigned_location(int grid[][9]) {
#   for (int row = 0; row < 9; row++) {
#     for (int col = 0; col < 9; col++) {
#       if (grid[row][col] == 0) {
#         return std::make_pair(row, col);
#       }
#     }
#   }
#   return GRID_FULL;
# }

def solve_soduko(grid):
  if (GRID_FULL == get_unassigned_location(grid)):
    return true; 

  # std::pair<int, int> row_and_col = get_unassigned_location(grid);
  # int row = row_and_col.first;
  # int col = row_and_col.second;
  
  for (num = 1; num <= 9; num++):
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

def main():
  print('\n************************************\n----------- Solve Sudoku -----------\n************************************\n')

  # w, h = 9
  # grid = [[0 for x in range(w)] for y in range(h)]

  grid = [
    [ 0, 9, 0, 0, 0, 0, 8, 5, 3 ],
    [ 0, 0, 0, 8, 0, 0, 0, 0, 4 ],
    [ 0, 0, 8, 2, 0, 3, 0, 6, 9 ],
    [ 5, 7, 4, 0, 0, 2, 0, 0, 0 ],
    [ 0, 0, 0, 0, 0, 0, 0, 0, 0 ],
    [ 0, 0, 0, 9, 0, 0, 6, 3, 7 ],
    [ 9, 4, 0, 1, 0, 8, 5, 0, 0 ],
    [ 7, 0, 0, 0, 0, 6, 0, 0, 0 ],
    [ 6, 8, 2, 0, 0, 0, 0, 9, 0 ],
  ]

  print_grid(grid);

  if (solve_soduko(grid) == true):
    print('\nSolution Found.\n')
    print_grid(grid);
  else:
    print('No solution exists.\n\n')

main()
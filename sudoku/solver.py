import time

current_milli_time = lambda: int(round(time.time() * 1000))

grid_full = False
count = 0

def print_grid(grid):
  for i in range(9):
    print('\n-------------------------------------')
    for j in range(9):
      print(' ', end='')
      if grid[i][j] == 0:
        print(' ', end='')
      else:
        print(grid[i][j], end='')
      print(' |', end='')
  print('\n-------------------------------------\n')

# check if valid in row
def exists_in_row(grid, row, num):
  for col in range(9):
    if grid[row][col] == num:
      return True
  return False

# check if valid in column
def exists_in_column(grid, col, num):
  for row in range(9):
    if grid[row][col] == num:
      return True
  return False

# check if valid in square
def exists_in_box(grid, box_start_row, box_start_col, num):
  for row in range(3):
    for col in range(3):
      if grid[row + box_start_row][col + box_start_col] == num:
        return True
  return False

# check if possible placement by validating with above functions
def validate_placement(grid, row, col, num):
  in_row = exists_in_row(grid, row, num)
  in_col = exists_in_column(grid, col, num)
  in_box = exists_in_box(grid, row - row % 3, col - col % 3, num)
  return (not in_row) and (not in_col) and (not in_box)

def get_unassigned_location(grid):
  for row in range(9):
    for col in range(9):
      if grid[row][col] == 0:
        return [row, col]
  global grid_full
  grid_full = True

def solve_soduko(grid):
  row_and_col = get_unassigned_location(grid)

  if grid_full:
    return True

  row = row_and_col[0]
  col = row_and_col[1]
  
  for num in range(1, 10):
    if validate_placement(grid, row, col, num):
      grid[row][col] = num
      global count 
      count += 1
      print('Trying again - (%d guesses)' % count)
      
      if solve_soduko(grid):
        return True
      grid[row][col] = 0
  return False

def main():
  time_start = current_milli_time()
  print('\n************************************')
  print('----------- Solve Sudoku -----------')
  print('************************************')

  # w, h = 9
  # grid = [[0 for x in range(w)] for y in range(h)]

  grid = [
    [ 4, 3, 0, 7, 0, 0, 0, 0, 0 ],
    [ 0, 0, 7, 9, 3, 0, 0, 0, 0 ],
    [ 1, 6, 0, 0, 0, 8, 0, 0, 0 ],
    [ 7, 0, 0, 0, 0, 0, 4, 0, 0 ],
    [ 0, 0, 0, 3, 2, 9, 0, 0, 0 ],
    [ 0, 0, 5, 0, 0, 0, 0, 0, 9 ],
    [ 0, 0, 0, 2, 0, 0, 0, 6, 8 ],
    [ 0, 0, 0, 0, 8, 1, 7, 0, 0 ],
    [ 0, 0, 0, 0, 0, 4, 0, 3, 5 ],
  ]

  print_grid(grid)

  if solve_soduko(grid):
    time_end = current_milli_time()
    total_time = (time_end - time_start) / 1000.0
    print('\nSolution Found in %f seconds.' % total_time)
    print_grid(grid)
  else:
    time_end = current_milli_time()
    print('No solution exists.\n')

main()
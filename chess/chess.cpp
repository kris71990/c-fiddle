#include <iostream>

void drawBoard(char startPosition[][8]) {
  for (int x = 0; x < 8; x++) {
    std::cout << "\n------------------------------------------------\n";
    for (int y = 0; y < 8; y++) {
      std::cout << "  " << startPosition[x][y] << "  |";
    }
  }
  std::cout << "\n------------------------------------------------\n\n";
}

int main() {
  char startPosition[8][8] = {
    { 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
    { 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X' },
    { '-', '-', '-', '-', '-', '-', '-', '-' },
    { '-', '-', '-', '-', '-', '-', '-', '-' },
    { '-', '-', '-', '-', '-', '-', '-', '-' },
    { '-', '-', '-', '-', '-', '-', '-', '-' },
    { 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y' },
    { 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y' },
  };
  drawBoard(startPosition);
  return 0;
}
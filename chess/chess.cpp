#include <iostream>
#include <map>

bool game_end = false;
int turn = 0;

// void boardLocationMap() {
//   std::map<char, int> parseBoardLocation;

//   for (int i = 0; i < 8; i++) {

//   }
// }

void drawBoard(char currentPosition[][8]) {
  std::cout << "\n  a  |  b  |  c  |  d  |  e  |  f  |  g  |  h  | \n";
  for (int x = 0; x < 8; x++) {
    std::cout << "\n------------------------------------------------\n";
    for (int y = 0; y < 8; y++) {
      std::cout << "  " << currentPosition[x][y] << "  |";
    }
    std::cout << "  " << std::abs(x - 8);
  }
  std::cout << "\n------------------------------------------------\n\n";
}

void movePiece(char currentPosition[][8]) {
  std::string spaceFrom;
  std::string spaceTo;
  std::cout << "Select space to move from: ";
  std::cin >> spaceFrom;
  std::cout << "Select space to move to: ";
  std::cin >> spaceTo;

  if (spaceFrom.length() != 2 || spaceTo.length() != 2) throw std::string("Improper input");

  char letterTo, letterFrom;
  int numberTo, numberFrom;
  for (int i = 0; i < spaceFrom.length(); i++) {
    if (i == 0) {
      letterFrom = spaceFrom[i];
      letterTo = spaceTo[i];
    } else {
      numberFrom = spaceFrom[i] - '0';
      numberTo = spaceTo[i] - '0';
    }
  }
  int xTo, yTo;
  int xFrom, yFrom;
  xTo = std::abs(numberTo - 8);
  yTo = int(letterTo) - '0' - 49;
  xFrom = std::abs(numberFrom - 8);
  yFrom = int(letterFrom) - '0' - 49;

  if (currentPosition[xTo][yTo] == ' ') {
    if (turn % 2 == 0) {
      currentPosition[xTo][yTo] = 'W';
      currentPosition[xFrom][yFrom] = ' ';
    } else {
      currentPosition[xTo][yTo] = 'B';
      currentPosition[xFrom][yFrom] = ' ';
    }
  }
  turn++;
}

int main() {
  char currentPosition[8][8] = {
    { 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B' },
    { 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B' },
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
    { 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
    { 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
  };

  while (!game_end) {
    drawBoard(currentPosition);
    movePiece(currentPosition);
  }
  return 0;
}
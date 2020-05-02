#include <iostream>
#include <map>
#include <array>

struct State
{
  bool game_end;
  int turn;
};

// void boardLocationMap() {
//   std::map<char, int> parseBoardLocation;

//   for (int i = 0; i < 8; i++) {

//   }
// }

void drawBoard(std::array<std::array<char, 8>, 8>& board) 
{
  std::cout << "\n  a  |  b  |  c  |  d  |  e  |  f  |  g  |  h  | \n";

  for (int x = 0; x < 8; x++) 
  {
    std::cout << "\n------------------------------------------------\n";
    for (int y = 0; y < 8; y++) 
    {
      std::cout << "  " << board[x][y] << "  |";
    }
    std::cout << "  " << std::abs(x - 8);
  }
  std::cout << "\n------------------------------------------------\n\n";
}

bool movePiece(std::array<std::array<char, 8>, 8>& board, State& game_state) 
{
  std::string spaceFrom;
  std::string spaceTo;
  std::cout << "Select space to move from: ";
  std::cin >> spaceFrom;
  std::cout << "Select space to move to: ";
  std::cin >> spaceTo;

  if (spaceFrom == "q" || spaceTo == "q") 
  {
    game_state.game_end = true;
    return false;
  }
  if (spaceFrom.length() != 2 || spaceTo.length() != 2)
  {
    return false;
  };

  char letterTo, letterFrom;
  int numberTo, numberFrom;
  for (int i = 0; i < spaceFrom.length(); i++) 
  {
    if (i == 0) 
    {
      letterFrom = spaceFrom[i];
      letterTo = spaceTo[i];
    } 
    else 
    {
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

  if (board[xTo][yTo] == ' ') 
  {
    if (game_state.turn % 2 == 0) 
    {
      board[xTo][yTo] = 'W';
      board[xFrom][yFrom] = ' ';
    } else {
      board[xTo][yTo] = 'B';
      board[xFrom][yFrom] = ' ';
    }
  }
  game_state.turn++;
  return true;
}

int main() 
{
  State game_state = { 0, 0 };

  std::array<std::array<char, 8>, 8> board = {
    {
      { 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B' },
      { 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B' },
      { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
      { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
      { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
      { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
      { 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
      { 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
    }
  };

  while (game_state.game_end == 0) 
  {
    drawBoard(board);
    movePiece(board, game_state);
  }
  return 0;
}
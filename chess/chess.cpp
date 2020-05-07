#include <iostream>
#include <string>
#include <map>
#include <array>

#include "Pawn.hpp"

struct State {
  bool game_end;
  int turn;
};

// void boardLocationMap() {
//   std::map<char, int> parseBoardLocation;

//   for (int i = 0; i < 8; i++) {

//   }
// }

void drawBoard(const std::array<std::array<char, 8>, 8>& board) 
{
  std::cout << "\n  a  |  b  |  c  |  d  |  e  |  f  |  g  |  h  | \n";

  for (int x = 0; x < 8; ++x) {
    std::cout << "\n------------------------------------------------\n";
    for (int y = 0; y < 8; ++y) {
      std::cout << "  " << board[x][y] << "  |";
    }
    std::cout << "  " << std::abs(x - 8);
  }
  std::cout << "\n------------------------------------------------\n\n";
}

auto player_print(const int turn) {
  std::string color;
  if (turn % 2 == 0) {
    color = "White Move";
  } else {
    color = "Black Move";
  }
  return [&]{ std::cout << color << '\n'; };
}

bool movePiece(std::array<std::array<char, 8>, 8>& board, State& game_state) 
{
  std::string spaceFrom;
  std::string spaceTo;
  
  auto print = player_print(game_state.turn);
  print();

  std::cout << "Select space to move from: ";
  std::cin >> spaceFrom;
  std::cout << "Select space to move to: ";
  std::cin >> spaceTo;

  if (spaceFrom == "q" || spaceTo == "q") {
    game_state.game_end = true;
    return false;
  }

  if (spaceFrom.length() != 2 || spaceTo.length() != 2) {
    return false;
  };

  char letterTo, letterFrom;
  int numberTo, numberFrom;
  for (int i = 0; i < spaceFrom.length(); ++i) {
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

  // if (white), else (black)
  if (game_state.turn % 2 == 0) {
    if (board[xFrom][yFrom] != 'W') {
      return false;
    }

    if (board[xTo][yTo] == ' ') {
      board[xTo][yTo] = 'W';
      board[xFrom][yFrom] = ' ';
    } // else capture()
  } else {
    if (board[xFrom][yFrom] != 'B') {
      return false;
    }

    if (board[xTo][yTo] == ' ') {
      board[xTo][yTo] = 'B';
      board[xFrom][yFrom] = ' ';
    } // else capture()
  }

  ++game_state.turn;
  return true;
}

int main() 
{
  State game_state = { false, 0 };

  std::map<int, Pawn> pieces;
  Pawn b_pawn('B', 'a', 1);

  // for (int i = 0; i < 8; ++i) {
  //   pieces[i] = Pawn('B', 'a', 1);
  // }

  // for (std::map<int, Piece>::iterator it = pieces.begin(); it != pieces.end();) {
  //   std::cout << it -> first << it -> second.get_coordinates();
  //   ++it;
  // }

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

  while (game_state.game_end == false) {
    drawBoard(board);
    movePiece(board, game_state);
  }
  return 0;
}
#include <iostream>
#include <string>
#include <array>

#include "Board.hpp"

struct State {
  bool game_end;
  int turn;
};

auto player_print(const std::string color) {
  return [&]{ std::cout << color << '\n'; };
}

bool movePiece(std::array<std::array<std::string, 8>, 8>& board, State& game_state) 
{
  std::string spaceFrom;
  std::string spaceTo;

  std::string color;
  if (game_state.turn % 2 == 0) {
    color = "White Move";
  } else {
    color = "Black Move";
  }
  
  auto print = player_print(color);
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
    if (board[xFrom][yFrom] != "W") {
      return false;
    }

    if (board[xTo][yTo] == " ") {
      board[xTo][yTo] = "W";
      board[xFrom][yFrom] = " ";
    } // else capture()
  } else {
    if (board[xFrom][yFrom] != "B") {
      return false;
    }

    if (board[xTo][yTo] == " ") {
      board[xTo][yTo] = "B";
      board[xFrom][yFrom] = " ";
    } // else capture()
  }

  ++game_state.turn;
  return true;
}

int main() 
{
  State game_state = { false, 0 };
  Board board;
  board.init();

  // board = {
  //   {
  //     { 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B' },
  //     { 'B', 'B', 'B', 'B', 'B', 'B', 'B', 'B' },
  //     { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
  //     { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
  //     { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
  //     { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
  //     { 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
  //     { 'W', 'W', 'W', 'W', 'W', 'W', 'W', 'W' },
  //   }
  // };

  while (game_state.game_end == false) {
    board.draw_board();
    movePiece(board.board, game_state);
  }
  return 0;
}
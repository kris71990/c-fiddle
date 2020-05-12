#include <iostream>
#include <string>
#include <array>
#include <vector>

#include "Board.hpp"

namespace move_functions {
  
}

// turn % 2 == 0 -> white
// turn % 2 == 1 -> black

struct State {
  bool game_end;
  int turn;
};

auto player_print(const std::string color) { return [&]{ std::cout << color << '\n'; }; }
bool is_on_board(int x, int y) { return ((x < 8 && x >= 0) && (y < 8 && y >= 0)) ? true : false; }

std::vector<std::array<int, 2>> pawn_moves(std::array<std::array<std::string, 8>, 8>& board, int turn, int x, int y) 
{
  std::vector<std::array<int, 2>> moves;
  if (turn % 2 == 0) {
    if (x == 6) {
      if (board[x - 1][y] == " " && board[x - 2][y] == " ") {
        moves.push_back({ x - 2, y });
        moves.push_back({ x - 1, y });
      }
    } else {
      if (is_on_board(x - 1, y)) moves.push_back({ x - 1, y });
    }
  } else {
    if (x == 1) {
      if (board[x + 1][y] == " " && board[x + 2][y] == " ") {
        moves.push_back({ x + 2, y });
        moves.push_back({ x + 1, y });
      }
    } else {
      if (is_on_board(x + 1, y)) moves.push_back({ x + 1, y });
    }
  }
  return moves;
}

std::vector<std::array<int, 2>> king_moves(std::array<std::array<std::string, 8>, 8>& board, int turn, int x, int y) 
{
  std::vector<std::array<int, 2>> moves;
  if (x + 1 < 8) moves.push_back({ x + 1, y });
  if (x - 1 > 0) moves.push_back({ x - 1, y });
  if (y + 1 < 8) moves.push_back({ x, y + 1 });
  if (y - 1 > 0) moves.push_back({ x, y - 1 });
  return moves;
}

std::string is_valid_move(Board& board, int turn, int xFrom, int yFrom, int xTo, int yTo) 
{
  if (!is_on_board(xTo, yTo)) { return ""; }

  std::map<Board::Position, Board::Piece>::iterator it;
  std::vector<std::array<int, 2>> possible_moves;

  if (turn % 2 == 0) {
    it = board.white_pieces.find(Board::Position(xFrom, yFrom));

    if (it != board.white_pieces.end()) {
      std::string piece_type = board.board_chars[it -> second];
      if (piece_type == "P") {
        possible_moves = pawn_moves(board.board, turn, it -> first.x, it -> first.y);
        for (std::array<int, 2>& move : possible_moves) {
          if (move[0] == xTo && move[1] == yTo) {
            return "\x1b[1;97m" + piece_type;
          }
        }
      } else if (piece_type == "K") {
        possible_moves = king_moves(board.board, turn, it -> first.x, it -> first.y);
        for (std::array<int, 2>& move : possible_moves) {
          if (move[0] == xTo && move[1] == yTo) {
            return "\x1b[1;97m" + piece_type;
          }
        }
      }
    } else {
      return "";
    }
  } else {
    it = board.black_pieces.find(Board::Position(xFrom, yFrom));

    if (it != board.black_pieces.end()) {
      std::string piece_type = board.board_chars[it -> second];
      if (piece_type == "P") {
        possible_moves = pawn_moves(board.board, turn, it -> first.x, it -> first.y);
        for (std::array<int, 2>& move : possible_moves) {
          if (move[0] == xTo && move[1] == yTo) {
            return "\x1b[1;30m" + piece_type;
          }
        }
      } else if (piece_type == "K") {
        possible_moves = king_moves(board.board, turn, it -> first.x, it -> first.y);
        for (std::array<int, 2>& move : possible_moves) {
          if (move[0] == xTo && move[1] == yTo) {
            return "\x1b[1;30m" + piece_type;
          }
        }
      }
    } else {
      return "";
    }
  }
  return "";
}

bool movePiece(Board& board, State& game_state) 
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

  std::string moved_piece = is_valid_move(board, game_state.turn, xFrom, yFrom, xTo, yTo);

  if (!moved_piece.empty()) {
    board.board[xTo][yTo] = moved_piece;
    board.board[xFrom][yFrom] = " ";
    ++game_state.turn;
    std::cout << "moved";
  } else {
    std::cout << "invalid move";
  }
  // else capture()
  return true;
}

int main() 
{
  State game_state = { false, 0 };
  Board board;
  board.init();

  while (game_state.game_end == false) {
    board.draw_board();
    movePiece(board, game_state);
  }
  return 0;
}
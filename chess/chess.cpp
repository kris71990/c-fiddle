#include <iostream>
#include <string>
#include <array>
#include <vector>

#include "Board.hpp"

namespace move_functions {
  
}

struct State {
  bool game_end;
  int turn;
};

auto player_print(const std::string color) {
  return [&]{ std::cout << color << '\n'; };
}

std::vector<std::array<int, 2>> pawn_moves(Board& board, int turn, int x, int y) 
{
  std::vector<std::array<int, 2>> moves;
  if (turn % 2 == 0) {
    if (x == 6) {
      if (board.board[x - 1][y] == " " && board.board[x - 2][y] == " ") {
        moves.push_back({ x - 2, y });
        moves.push_back({ x - 1, y });
      }
    } else {
      moves.push_back({ x + 1, y });
    }
  } else {
    if (x == 1) {
      if (board.board[x + 1][y] == " " && board.board[x + 2][y] == " ") {
        moves.push_back({ x + 2, y });
        moves.push_back({ x + 1, y });
      }
    } else {
      moves.push_back({ x + 1, y });
    }
  }
  return moves;
}

std::string is_valid_move(Board& board, int turn, int xFrom, int yFrom, int xTo, int yTo) 
{
  std::map<Board::Pos, Board::Piece>::iterator it;
  std::vector<std::array<int, 2>> possible_moves;

  if (turn % 2 == 0) {
    it = board.white_pieces.find(Board::Pos(xFrom, yFrom));

    if (it != board.white_pieces.end()) {
      std::string piece_type = board.board_chars[it -> second];
      if (piece_type == "P") {
        possible_moves = pawn_moves(board, turn, it -> first.x, it -> first.y);
        for (std::array<int, 2>& move : possible_moves) {
          if (move[0] == xTo && move[1] == yTo) {
            return piece_type;
          }
        }
      }
    } else {
      return "";
    }
  } else {
    it = board.black_pieces.find(Board::Pos(xFrom, yFrom));

    if (it != board.black_pieces.end()) {
      std::string piece_type = board.board_chars[it -> second];
      if (piece_type == "P") {
        possible_moves = pawn_moves(board, turn, it -> first.x, it -> first.y);
        for (std::array<int, 2>& move : possible_moves) {
          if (move[0] == xTo && move[1] == yTo) {
            return piece_type;
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
    std::cout << "moved";
  } 
  // else capture()

  ++game_state.turn;
  return true;
}

int main() 
{
  State game_state = { false, 0 };
  Board board;
  board.init();

  // std::map<Board::Pos, Board::Piece>::iterator it;
  // it = board.white_pieces.find(Board::Pos(6,0));
  // if (it != board.white_pieces.end()) {
  //   std::cout << it -> first.x << it -> first.y;
  // }

  // for (std::pair<Board::Pos, Board::Piece> map : board.white_pieces) {
  //   std::cout << map.first.x << map.first.y << "\n"; //board.board_chars[map.second] << "\n";
  // }

  while (game_state.game_end == false) {
    board.draw_board();
    movePiece(board, game_state);
  }
  return 0;
}
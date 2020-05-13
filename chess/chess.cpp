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

auto player_print(const std::string color) { return [&]{ std::cout << color; }; }

bool is_on_board(int x, int y) { 
  return ((x < 8 && x >= 0) && (y < 8 && y >= 0)) ? true : false; 
}

bool is_unoccupied(const std::array<std::array<std::string, 8>, 8>& board, int x, int y) {
  return board[x][y] == " " ? true : false;
}

std::vector<std::array<int, 2>> pawn_moves(std::array<std::array<std::string, 8>, 8>& board, int turn, int x, int y) 
{
  std::vector<std::array<int, 2>> moves;
  if (turn % 2 == 0) {
    if (x == 6) {
      if (is_unoccupied(board, x - 2, y) && is_unoccupied(board, x - 1, y)) {
        moves.push_back({ x - 2, y });
        moves.push_back({ x - 1, y });
      }
    } else {
      if (is_on_board(x - 1, y) && is_unoccupied(board, x - 1, y)) moves.push_back({ x - 1, y });
    }
  } else {
    if (x == 1) {
      if (is_unoccupied(board, x + 2, y) && is_unoccupied(board, x + 1, y)) {
        moves.push_back({ x + 2, y });
        moves.push_back({ x + 1, y });
      }
    } else {
      if (is_on_board(x + 1, y) && is_unoccupied(board, x + 1, y)) moves.push_back({ x + 1, y });
    }
  }
  return moves;
}

std::vector<std::array<int, 2>> king_moves(std::array<std::array<std::string, 8>, 8>& board, int turn, int x, int y) 
{
  std::vector<std::array<int, 2>> moves;
  int count = 0; 
  int count1 = 0;
  int count2 = -1;

  for (int i = 0; i < 8; ++i) {
    switch (i % 3) {
      case 0: { 
        if (is_on_board(x - 1, y - 1 + count) && is_unoccupied(board, x - 1, y - 1 + count)) {
          moves.push_back({ x - 1, y - 1 + count });
        }
        ++count;
        break;
      }
      case 1: {
        if (is_on_board(x + 1, y - 1 + count1) && is_unoccupied(board, x + 1, y - 1 + count1)) {
          moves.push_back({ x + 1, y - 1 + count1 });
        }
        ++count1;
        break;
      }
      default: {
        if (is_on_board(x, y + count2) && is_unoccupied(board, x, y + count2)) {
          moves.push_back({ x, y + count2 });
        }
        count2 = 1;
        break;
      }
    }
  }
  return moves;
}

std::string is_valid_move(Board& board, int turn, int xFrom, int yFrom, int xTo, int yTo) 
{
  if (!is_on_board(xTo, yTo)) { return ""; }

  std::map<Board::Position, Board::Piece>::iterator it_from;
  std::vector<std::array<int, 2>> possible_moves;

  if (turn % 2 == 0) {
    std::map<Board::Position, Board::Piece>::iterator it_to_white;
    // check if white piece on destination
    it_to_white = board.white_pieces.find(Board::Position(xTo, yTo));
    if (it_to_white != board.white_pieces.end()) { return ""; }

    // check if black piece on destination - capture
    // it_to_black = board.black_pieces.find(Board::Position(xTo, yTo));
    // if (it_to_black != board.black_pieces.end()) capture();

    it_from = board.white_pieces.find(Board::Position(xFrom, yFrom));

    if (it_from != board.white_pieces.end()) {
      std::string piece_type = board.board_chars[it_from -> second];
      if (piece_type == "P") {
        possible_moves = pawn_moves(board.board, turn, it_from -> first.x, it_from -> first.y);
        for (std::array<int, 2>& move : possible_moves) {
          if (move[0] == xTo && move[1] == yTo) {
            return piece_type;
          }
        }
      } else if (piece_type == "K") {
        possible_moves = king_moves(board.board, turn, it_from -> first.x, it_from -> first.y);
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
    std::map<Board::Position, Board::Piece>::iterator it_to_black;
    // check if black piece on destination
    it_to_black = board.black_pieces.find(Board::Position(xTo, yTo));
    if (it_to_black != board.black_pieces.end()) { return ""; }

    // check if white piece on destination - capture
    // it_to_white = board.white_pieces.find(Board::Position(xTo, yTo));
    // if (it_to_white != board.white_pieces.end()) capture();

    it_from = board.black_pieces.find(Board::Position(xFrom, yFrom));

    if (it_from != board.black_pieces.end()) {
      std::string piece_type = board.board_chars[it_from -> second];
      if (piece_type == "P") {
        possible_moves = pawn_moves(board.board, turn, it_from -> first.x, it_from -> first.y);
        for (std::array<int, 2>& move : possible_moves) {
          if (move[0] == xTo && move[1] == yTo) {
            return piece_type;
          }
        }
      } else if (piece_type == "K") {
        possible_moves = king_moves(board.board, turn, it_from -> first.x, it_from -> first.y);
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
    color = "White";
  } else {
    color = "Black";
  }
  
  auto print_color = player_print(color);
  
  print_color(); std::cout << " to move\n";
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
  
  Board::Piece piece;
  if (moved_piece == "P") {
    piece = Board::Piece::pawn;
  } else if (moved_piece == "K") {
    piece = Board::Piece::king;
  } else if (moved_piece == "Q") {
    piece = Board::Piece::queen;
  } else if (moved_piece == "B") {
    piece = Board::Piece::bishop;
  } else if (moved_piece == "Kn") {
    piece = Board::Piece::knight;
  } else {
    piece = Board::Piece::rook;
  }

  if (!moved_piece.empty()) {
    if (game_state.turn % 2 == 0) {
      std::map<Board::Position, Board::Piece>::iterator it;
      it = board.white_pieces.find(Board::Position(xFrom, yFrom));
      board.white_pieces.erase(it);

      board.white_pieces[Board::Position(xTo, yTo)] = piece;
      board.board[xTo][yTo] = moved_piece; //"\x1b[1;97m"
    } else {
      std::map<Board::Position, Board::Piece>::iterator it;
      it = board.black_pieces.find(Board::Position(xFrom, yFrom));
      board.black_pieces.erase(it);

      board.black_pieces[Board::Position(xTo, yTo)] = piece;
      board.board[xTo][yTo] = moved_piece; //"\x1b[1;30m" 
    }
    board.board[xFrom][yFrom] = " ";
    print_color(); 
    std::cout << ": " << moved_piece << " from " << letterFrom << numberFrom << " to " << letterTo << numberTo << "\n";
    ++game_state.turn;
  } else {
    std::cout << "\nInvalid Move\n";
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
#include <iostream>
#include "Board.hpp"

void Board::init()
{
  for (int i = 0; i < 8; ++i) {
    black_pieces[Position(1, i)] = Piece::pawn;
    white_pieces[Position(6, i)] = Piece::pawn;
    
    if (i == 0 || i == 7) {
      black_pieces[Position(0, i)] = Piece::rook;
      white_pieces[Position(7, i)] = Piece::rook;
    }

    if (i == 1 || i == 6) {
      black_pieces[Position(0, i)] = Piece::knight;
      white_pieces[Position(7, i)] = Piece::knight;
    }

    if (i == 2 || i == 5) {
      black_pieces[Position(0, i)] = Piece::bishop;
      white_pieces[Position(7, i)] = Piece::bishop;
    }

    if (i == 3) {
      black_pieces[Position(0, i)] = Piece::queen;
      white_pieces[Position(7, i)] = Piece::queen;
    }

    if (i == 4) {
      black_pieces[Position(0, i)] = Piece::king;
      white_pieces[Position(7, i)] = Piece::king;
    }
  }

  for (int i = 0; i < 8; ++i) { board[i].fill(" "); }

  std::map<Position, Piece>::iterator it;
  for (it = white_pieces.begin(); it != white_pieces.end(); ++it) {
    board[it -> first.x][it -> first.y] = "\x1b[1;97m" + board_chars[it -> second]; //"\x1b[1;97m"
  }

  for (it = black_pieces.begin(); it != black_pieces.end(); ++it) {
    board[it -> first.x][it -> first.y] = "\x1b[1;30m" + board_chars[it -> second]; //"\x1b[1;30m" + 
  }
}

void Board::draw_board() 
{
  std::cout << "\n  a  |  b  |  c  |  d  |  e  |  f  |  g  |  h  | \n";

  for (int x = 0; x < 8; ++x) {
    std::cout << "\n------------------------------------------------\n";
    for (int y = 0; y < 8; ++y) {
      // std::cout << "  " << board[x][y] << "  |";
      if (board[x][y] == "\x1b[1;97mKn" || board[x][y] == "\x1b[1;30mKn") {
        if ((x % 2 == 1 && y % 2 == 0) || (x % 2 == 0 && y % 2 == 1)) {
          std::cout << "\x1b[100m  " << board[x][y] << " \x1b[0m\x1b[0m|";
        } else {
          std::cout << "\x1b[46m  " << board[x][y] << " \x1b[0m\x1b[0m|";
        }
      } else {
        if ((x % 2 == 1 && y % 2 == 0) || (x % 2 == 0 && y % 2 == 1)) {
          std::cout << "\x1b[100m  " << board[x][y] << "  \x1b[0m\x1b[0m|";
        } else {
          std::cout << "\x1b[46m  " << board[x][y] << "  \x1b[0m\x1b[0m|";
        }
      }
    }
    std::cout << "  " << std::abs(x - 8);
  }
  std::cout << "\n------------------------------------------------\n\n";
}

void Board::print_possible_moves(const std::vector<std::array<int, 2>>& moves) {
  std::map<int, char>::iterator it;
  for (const std::array<int, 2>& move : moves) {
    it = Board::grid_translator.find(move[1]);
    int invertedY = 8 - move[0];
    std::cout << it -> second << invertedY << "\n";
  }
}
#include <array>
#include <map>
#include <string>

#include "Pawn.hpp"
#include "Rook.hpp"
#include "Knight.hpp"
#include "Bishop.hpp"
#include "Queen.hpp"
#include "King.hpp"

class Board {
public:
  std::array<std::array<std::string, 8>, 8> board;
  std::map<int, Pawn> pawns;
  std::map<int, Rook> rooks;
  std::map<int, Knight> knights;
  std::map<int, Bishop> bishops;
  std::map<int, King> kings;
  std::map<int, Queen> queens;
  // std::map<int, Piece> white_pieces;
  
  void init();
  void draw_board();
};

template <typename B, typename T>
void place_pieces(B& board, std::map<int, T> input)
{
  for (typename std::map<int, T>::iterator it = input.begin(); it != input.end(); ++it) {
    board[it -> second.coordinateX][it -> second.coordinateY] = it -> second.board_char;
  }
}

void Board::init()
{
  for (int i = 0; i < 8; ++i) {
    pawns.insert(std::make_pair(i, Pawn('B', 1, i)));
    pawns.insert(std::make_pair(i + 8, Pawn('W', 6, i)));
    
    if (i == 0 || i == 7) {
      rooks.insert(std::make_pair(i + 16, Rook('B', 0, i)));
      rooks.insert(std::make_pair(i + 18, Rook('W', 7, i)));
    }

    if (i == 1 || i == 6) {
      knights.insert(std::make_pair(i + 20, Knight('B', 0, i)));
      knights.insert(std::make_pair(i + 22, Knight('W', 7, i)));
    }

    if (i == 2 || i == 5) {
      bishops.insert(std::make_pair(i + 24, Bishop('B', 0, i)));
      bishops.insert(std::make_pair(i + 26, Bishop('W', 7, i)));
    }

    if (i == 3) {
      queens.insert(std::make_pair(i + 28, Queen('B', 0, i)));
      queens.insert(std::make_pair(i + 29, Queen('W', 7, i)));
    }

    if (i == 4) {
      kings.insert(std::make_pair(i + 30, King('B', 0, i)));
      kings.insert(std::make_pair(i + 31, King('W', 7, i)));
    }
  }

  for (int i = 0; i < 8; ++i) {
    board[i].fill(" ");
  }

  place_pieces(board, pawns);
  place_pieces(board, rooks);
  place_pieces(board, knights);
  place_pieces(board, bishops);
  place_pieces(board, kings);
  place_pieces(board, queens);
}

void Board::draw_board() 
{
  std::cout << "\n  a  |  b  |  c  |  d  |  e  |  f  |  g  |  h  | \n";

  for (int x = 0; x < 8; ++x) {
    std::cout << "\n------------------------------------------------\n";
    for (int y = 0; y < 8; ++y) {
      if (board[x][y] == "Kn") {
         if ((x % 2 == 1 && y % 2 == 0) || (x % 2 == 0 && y % 2 == 1)) {
          std::cout << "\x1b[40m\x1b[1;92m  " << board[x][y] << " \x1b[0m\x1b[0m|";
        } else {
          std::cout << "\x1b[100m\x1b[1;92m  " << board[x][y] << " \x1b[0m\x1b[0m|";
        }
      } else {
        if ((x % 2 == 1 && y % 2 == 0) || (x % 2 == 0 && y % 2 == 1)) {
          std::cout << "\x1b[40m\x1b[1;92m  " << board[x][y] << "  \x1b[0m\x1b[0m|";
        } else {
          std::cout << "\x1b[100m\x1b[1;92m  " << board[x][y] << "  \x1b[0m\x1b[0m|";
        }
      }
    }
    std::cout << "  " << std::abs(x - 8);
  }
  std::cout << "\n------------------------------------------------\n\n";
}
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
  
  void init();
  void draw_board();
};

// void _init_fill()
// {
//   for (int i = 0; i < 8; ++i) {
//     board[i].fill(' ');
//   }
// }

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

  for (std::map<int, Pawn>::iterator it = pawns.begin(); it != pawns.end(); ++it) {
    board[it -> second.coordinateX][it -> second.coordinateY] = it -> second.board_char;
  }

  for (std::map<int, Rook>::iterator it = rooks.begin(); it != rooks.end(); ++it) {
    board[it -> second.coordinateX][it -> second.coordinateY] = it -> second.board_char;
  }

  for (std::map<int, Knight>::iterator it = knights.begin(); it != knights.end(); ++it) {
    board[it -> second.coordinateX][it -> second.coordinateY] = it -> second.board_char;
  }

  for (std::map<int, Bishop>::iterator it = bishops.begin(); it != bishops.end(); ++it) {
    board[it -> second.coordinateX][it -> second.coordinateY] = it -> second.board_char;
  }

  for (std::map<int, Queen>::iterator it = queens.begin(); it != queens.end(); ++it) {
    board[it -> second.coordinateX][it -> second.coordinateY] = it -> second.board_char;
  }

  for (std::map<int, King>::iterator it = kings.begin(); it != kings.end(); ++it) {
    board[it -> second.coordinateX][it -> second.coordinateY] = it -> second.board_char;
  }
    // {
    //   std::make_pair(0, Pawn('B', 1, 0)),
    //   std::make_pair(1, Pawn('B', 1, 1)),
    //   std::make_pair(2, Pawn('B', 1, 2)),
    //   std::make_pair(3, Pawn('B', 1, 3)),
    //   std::make_pair(4, Pawn('B', 1, 4)),
    //   std::make_pair(5, Pawn('B', 1, 5)),
    //   std::make_pair(6, Pawn('B', 1, 6)),
    //   std::make_pair(7, Pawn('B', 1, 7)),
    //   std::make_pair(8, Pawn('W', 6, 0)),
    //   std::make_pair(9, Pawn('W', 6, 1)),
    //   std::make_pair(10, Pawn('W', 6, 2)),
    //   std::make_pair(11, Pawn('W', 6, 3)),
    //   std::make_pair(12, Pawn('W', 6, 4)),
    //   std::make_pair(13, Pawn('W', 6, 5)),
    //   std::make_pair(14, Pawn('W', 6, 6)),
    //   std::make_pair(15, Pawn('W', 6, 7)),
    // };
}

void Board::draw_board() 
{
  std::cout << "\n  a  |  b  |  c  |  d  |  e  |  f  |  g  |  h  | \n";

  for (int x = 0; x < 8; ++x) {
    std::cout << "\n------------------------------------------------\n";
    for (int y = 0; y < 8; ++y) {
      if (board[x][y] == "Kn") {
        std::cout << "\x1b[32m  " << board[x][y] << " \x1b[0m|";
      } else {
        std::cout << "  " << board[x][y] << "  |";
      }
    }
    std::cout << "  " << std::abs(x - 8);
  }
  std::cout << "\n------------------------------------------------\n\n";
}
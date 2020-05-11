#include <array>
#include <map>
#include <string>

// #include "Pawn.hpp"
// #include "Rook.hpp"
// #include "Knight.hpp"
// #include "Bishop.hpp"
// #include "Queen.hpp"
// #include "King.hpp"

class Board {
public:
  enum class Piece {king, queen, pawn, rook, bishop, knight};
  std::array<std::array<std::string, 8>, 8> board;
  // std::map<int, Pawn> pawns;
  // std::map<int, Rook> rooks;
  // std::map<int, Knight> knights;
  // std::map<int, Bishop> bishops;
  // std::map<int, King> kings;
  // std::map<int, Queen> queens;

  struct Pos {
    int x,y;
    Pos(const Pos &p, int dx=0, int dy=0){ *this = p; x+=dx; y+=dy;}
    Pos(int _x, int _y) : x(_x), y(_y) {}
    bool operator<(const Pos & p) const { return (x < p.x) || (x==p.x && y < p.y); }
    bool operator==(const Pos & p) const { return x==p.x && y==p.y; }
    Pos(){x=-1;y=-1;}
  };

  std::map<Pos, Piece> white_pieces;
  std::map<Piece, std::string> board_chars =
    {
      { Piece::pawn, "P" },
      { Piece::rook, "R" },
      { Piece::knight, "Kn" },
      { Piece::bishop, "B" },
      { Piece::queen, "Q" },
      { Piece::king, "K" },
    };
  
  void init();
  void draw_board();
};

void Board::init()
{
  for (int i = 0; i < 8; ++i) {
    white_pieces[Pos(6, i)] = Piece::pawn;
    // pawns.insert(std::make_pair(i + 8, Pawn('W', 6, i)));
    
    if (i == 0 || i == 7) {
      // rooks.insert(std::make_pair(i + 16, Rook('B', 0, i)));
      white_pieces[Pos(7, i)] = Piece::rook;
    }

    if (i == 1 || i == 6) {
      // knights.insert(std::make_pair(i + 20, Knight('B', 0, i)));
      white_pieces[Pos(7, i)] = Piece::knight;
    }

    if (i == 2 || i == 5) {
      // bishops.insert(std::make_pair(i + 24, Bishop('B', 0, i)));
      white_pieces[Pos(7, i)] = Piece::bishop;
    }

    if (i == 3) {
      // queens.insert(std::make_pair(i + 28, Queen('B', 0, i)));
      white_pieces[Pos(7, i)] = Piece::queen;
    }

    if (i == 4) {
      // kings.insert(std::make_pair(i + 30, King('B', 0, i)));
      white_pieces[Pos(7, i)] = Piece::king;
    }
  }

  for (int i = 0; i < 8; ++i) {
    board[i].fill(" ");
  }

  for (std::map<Pos, Piece>::iterator it = white_pieces.begin(); it != white_pieces.end(); ++it) {
    board[it -> first.x][it -> first.y] = board_chars[it -> second];
  }
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
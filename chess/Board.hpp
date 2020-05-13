#include <array>
#include <map>
#include <string>

class Board {
public:
  enum class Piece { king, queen, pawn, rook, bishop, knight };
  std::array<std::array<std::string, 8>, 8> board;

  struct Position {
    int x,y;
    Position(const Position &p, int dx = 0, int dy = 0) { *this = p; x += dx; y += dy;}
    Position(int _x, int _y) : x(_x), y(_y) {}
    bool operator<(const Position &p) const { return (x < p.x) || (x == p.x && y < p.y); }
    bool operator==(const Position &p) const { return x == p.x && y == p.y; }
  };

  std::map<Position, Piece> white_pieces;
  std::map<Position, Piece> black_pieces;
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

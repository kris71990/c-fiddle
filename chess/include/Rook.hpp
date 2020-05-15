#include "Piece.hpp"

class Rook : public Piece {
public:
  Rook() : Piece(){}
  
  std::string type = "rook";
  std::string board_char = "R";
  bool move(int coordinateX, int coordinateY);
  std::string get_board_char() { return board_char; }
};

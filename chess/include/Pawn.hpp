#include "Piece.hpp"

class Pawn : public Piece {
public:
  Pawn() : Piece(){}
  
  std::string type = "pawn";
  std::string board_char = "P";
  bool move(int coordinateX, int coordinateY);
  std::string get_board_char() { return board_char; }
};
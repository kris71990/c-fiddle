#include "Piece.hpp"

class Pawn : public Piece {
public:
  Pawn(char player, int coordinateX, int coordinateY) : Piece(player, coordinateX, coordinateY){}
  
  std::string type = "pawn";
  std::string board_char = "P";
  bool move(int coordinateX, int coordinateY);
  std::string get_board_char() { return board_char; }
};
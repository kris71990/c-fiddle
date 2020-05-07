#include "Piece.hpp"

class Pawn : public Piece {
public:
  Pawn(char player, char coordinateX, int coordinateY) : Piece(player, coordinateX, coordinateY){}
  
  std::string type = "pawn";
  bool move(char coordinateX, int coordinateY);
};
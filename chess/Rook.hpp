#include "Piece.hpp"

class Rook : public Piece {
public:
  Rook(char player, int coordinateX, int coordinateY) : Piece(player, coordinateX, coordinateY){}
  
  std::string type = "rook";
  char board_char = 'R';
  bool move(int coordinateX, int coordinateY);
};

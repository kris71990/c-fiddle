#include "Piece.hpp"

class Pawn : public Piece
{
  Pawn Piece(char player, char coordinateX, int coordinateY);
  bool move(char coordinateX, int coordinateY);
};
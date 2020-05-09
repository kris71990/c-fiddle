#include "Piece.hpp"

class Pawn : public Piece {
public:
  Pawn(char player, int coordinateX, int coordinateY) : Piece(player, coordinateX, coordinateY){}
  
  std::string type = "pawn";
  char board_char = 'P';
  bool move(int coordinateX, int coordinateY);
  void get_board_char() { std::cout << board_char; }
};
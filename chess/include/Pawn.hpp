#include "Piece.hpp"

class Pawn : public Piece {
public:
  Pawn() : Piece(){}
  ~Pawn(){}
  
  std::string type = "pawn";
  std::string board_char = "P";
  std::string get_board_char() { return board_char; }

  bool move(int coordinateX, int coordinateY);
  bool validate_move(int turn, bool is_occupied, int xFrom, int yFrom, int xTo, int yTo);
};
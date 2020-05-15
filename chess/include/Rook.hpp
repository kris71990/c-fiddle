#include "Piece.hpp"

class Rook : public Piece {
public:
  Rook() : Piece(){}
  
  std::string type = "rook";
  std::string board_char = "R";
  std::string get_board_char() { return board_char; }

  bool validate_move(int turn, bool is_occupied, int xFrom, int yFrom, int xTo, int yTo);
  bool move(int coordinateX, int coordinateY);
};

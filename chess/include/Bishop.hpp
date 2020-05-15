#include <string>

#include "Piece.hpp"

class Bishop : public Piece {
public:
  Bishop() : Piece(){}
  
  std::string type = "bishop";
  std::string board_char = "B";
  std::string get_board_char() { return board_char; }

  bool validate_move(int turn, bool is_occupied, int xFrom, int yFrom, int xTo, int yTo);
};

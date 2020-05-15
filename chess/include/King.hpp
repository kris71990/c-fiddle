#include <string>

#include "Piece.hpp"

class King : public Piece {
public:
  King() : Piece(){}
  ~King(){}
  
  std::string board_char = "K";
  std::string get_board_char() { return board_char; }

  bool validate_move(int turn, bool is_occupied, int xFrom, int yFrom, int xTo, int yTo);
  bool move(int coordinateX, int coordinateY);
};

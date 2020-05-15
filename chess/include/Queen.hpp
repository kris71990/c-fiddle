#include <string>

#include "Piece.hpp"

class Queen : public Piece {
public:
  Queen() : Piece(){}
  
  std::string type = "queen";
  std::string board_char = "Q";
  std::string get_board_char() { return board_char; }

  bool move(int coordinateX, int coordinateY);
  bool validate_move(int turn, bool is_occupied, int xFrom, int yFrom, int xTo, int yTo);
};

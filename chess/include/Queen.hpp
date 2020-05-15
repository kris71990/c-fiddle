#include <string>

#include "Piece.hpp"

class Queen : public Piece {
public:
  Queen() : Piece(){}
  
  std::string type = "queen";
  std::string board_char = "Q";
  bool move(int coordinateX, int coordinateY);
  std::string get_board_char() { return board_char; }
};

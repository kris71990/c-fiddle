#include <string>

#include "Piece.hpp"

class King : public Piece {
public:
  King() : Piece(){}
  ~King(){}
  
  std::string board_char = "K";
  std::string get_board_char() { return board_char; }
  bool move(int coordinateX, int coordinateY);
};

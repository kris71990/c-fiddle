#include <string>

#include "Piece.hpp"

class Knight : public Piece {
public:
  Knight() : Piece(){}
  
  std::string type = "knight";
  std::string board_char = "Kn";
  bool move(int coordinateX, int coordinateY);
  std::string get_board_char() { return board_char; }
};

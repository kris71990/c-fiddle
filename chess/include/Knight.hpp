#include <string>

#include "Piece.hpp"

class Knight : public Piece {
public:
  Knight() : Piece(){}
  
  std::string type = "knight";
  std::string board_char = "Kn";
  std::string get_board_char() { return board_char; }

  bool validate_move(int turn, bool is_occupied, int xFrom, int yFrom, int xTo, int yTo);
  bool move(int coordinateX, int coordinateY);
};

#include <string>

#include "Piece.hpp"

class King : public Piece {
public:
  King(char player, int coordinateX, int coordinateY) : Piece(player, coordinateX, coordinateY){}
  
  std::string type = "king";
  std::string board_char = "K";
  bool move(int coordinateX, int coordinateY);
  void get_board_char() { std::cout << board_char; }
};

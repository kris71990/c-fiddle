#include <string>

#include "Piece.hpp"

class Knight : public Piece {
public:
  Knight(char player, int coordinateX, int coordinateY) : Piece(player, coordinateX, coordinateY){}
  
  std::string type = "knight";
  std::string board_char = "Kn";
  bool move(int coordinateX, int coordinateY);
  void get_board_char() { std::cout << board_char; }
};

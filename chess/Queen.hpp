#include <string>

#include "Piece.hpp"

class Queen : public Piece {
public:
  Queen(char player, int coordinateX, int coordinateY) : Piece(player, coordinateX, coordinateY){}
  
  std::string type = "queen";
  std::string board_char = "Q";
  bool move(int coordinateX, int coordinateY);
  void get_board_char() { std::cout << board_char; }
};

#include <string>

#include "Piece.hpp"

class Bishop : public Piece {
public:
  Bishop(char player, int coordinateX, int coordinateY) : Piece(player, coordinateX, coordinateY){}
  
  std::string type = "bishop";
  std::string board_char = "B";
  bool move(int coordinateX, int coordinateY);
  void get_board_char() { std::cout << board_char; }
};

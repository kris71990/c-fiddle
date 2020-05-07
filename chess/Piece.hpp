#include <string>
#include <iostream>

class Piece {
public:
  Piece(char p, char x, int y) : player(p), coordinateX(x), coordinateY(y){}

  std::string get_coordinates();
  void set_coordinates(char coordinateX, int coordinateY);

  char player;
  char coordinateX;
  int coordinateY;
};

std::string Piece::get_coordinates()
{
  return coordinateX + std::to_string(coordinateY);
}

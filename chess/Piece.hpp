#include <string>
#include <iostream>

class Piece {
public:
  Piece(char, char, int);

  std::string get_coordinates();
  void set_coordinates(char coordinateX, int coordinateY);

  char player;
  char coordinateX;
  int coordinateY;
};

Piece::Piece(char player1, char coordinateX1, int coordinateY1) 
{
  player = player1;
  coordinateX = coordinateX1;
  coordinateY = coordinateY1;
}

std::string Piece::get_coordinates()
{
  return coordinateX + std::to_string(coordinateY);
}

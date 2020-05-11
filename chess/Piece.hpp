#include <string>
#include <iostream>

#ifndef PIECE_H
#define PIECE_H

class Piece {
public:
  Piece(char p, int x, int y) : player(p), coordinateX(x), coordinateY(y){}

  std::string get_coordinates();
  void set_coordinates(int coordinateX, int coordinateY);
  virtual std::string get_board_char() = 0;

  char player;
  int coordinateX;
  int coordinateY;
};

// std::string Piece::get_coordinates()
// {
//   return std::to_string(coordinateX) + ' ' + std::to_string(coordinateY);
// }

#endif
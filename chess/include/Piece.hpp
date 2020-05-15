#include <string>
#include <iostream>

#ifndef PIECE_H
#define PIECE_H

class Piece {
public:
  Piece(){}
  virtual ~Piece(){}
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
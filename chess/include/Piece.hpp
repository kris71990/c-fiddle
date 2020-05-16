#include <string>

#ifndef PIECE_H
#define PIECE_H

class Piece {
public:
  Piece(){}
  virtual ~Piece(){}

  virtual std::string get_board_char() = 0;
  virtual bool validate_move(int turn, bool is_occupied, int xFrom, int yFrom, int xTo, int yTo) = 0;
};

#endif
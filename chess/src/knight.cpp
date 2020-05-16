#include "../include/Knight.hpp"

bool Knight::validate_move(int turn, bool is_occupoed, int xFrom, int yFrom, int xTo, int yTo) 
{
  if ((xFrom - 1 == xTo && yFrom - 2 == yTo) || 
      (xFrom - 2 == xTo && yFrom - 1 == yTo) ||
      (xFrom - 1 == xTo && yFrom + 2 == yTo) ||
      (xFrom - 2 == xTo && yFrom + 1 == yTo) ||
      (xFrom + 1 == xTo && yFrom - 2 == yTo) ||
      (xFrom + 2 == xTo && yFrom - 1 == yTo) ||
      (xFrom + 1 == xTo && yFrom + 2 == yTo) ||
      (xFrom + 2 == xTo && yFrom + 1 == yTo)) {
        return true;
  }
  return false;
}
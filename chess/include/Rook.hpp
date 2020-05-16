#include "Piece.hpp"

class Rook : public Piece {
public:
  Rook() : Piece(){}
  ~Rook(){}
  
  std::string type = "rook";
  std::string board_char = "R";
  std::string get_board_char() { return board_char; }

  bool validate_move(int turn, bool is_occupied, int xFrom, int yFrom, int xTo, int yTo);
  std::vector<std::array<int, 2>> possible_moves(const std::array<std::array<std::string, 8>, 8>& board, int turn, int x, int y);
};

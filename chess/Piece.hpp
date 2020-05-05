#include <string>

class Piece {
public:
  char coordinateX;
  int coordinateY;
  char player;
  
  std::string getCoordinates(char coordinateX, int coordinateY);
  std::string setCoordinates(char coordinateX, int coordinateY);
};

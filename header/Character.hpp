#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <vector>

enum CHARACTER_TYPE {
  BISHOP,
  PAWN,
  KING,
  QUEEN,
  KNIGHT,
  ROOK
};

class Character {
  protected:
    CHARACTER_TYPE Character_Type;
    std::string Character_Color;
    bool Character_AliveStatus = true;
  public:
    CHARACTER_TYPE getType() const;
    bool setAliveStatus();
    bool getAliveStatus() const;
    std::string getColor() const;
    virtual std::vector<std::string>* generatePossibleMoves(int x, int y) = 0;
};

#endif // CHARACTER_HPP
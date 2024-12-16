#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "../header/Character.hpp"

class Knight : public Character {
  public:
    Knight(std::string characterColor);
    virtual std::vector<std::string> getSpecificMoveStrings(Position currPosition, Board* gameBoard);
    virtual Character* clone();
};
 
#endif // KNIGHT_HPP 
#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "../header/Character.hpp"

class Knight : public Character {
  public:
    Knight(std::string characterColor);
    //std::vector<std::string>* generatePossibleMoves(int x, int y) override;
    virtual std::vector<std::string> getSpecificMoveStrings(Position currPosition, Board* gameBoard);
    virtual Character* clone();
};
 
#endif // KNIGHT_HPP 
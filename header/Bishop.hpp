#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "../header/Character.hpp"

class Bishop : public Character {
  public:
    Bishop(std::string characterColor);
    //std::vector<std::string>* generatePossibleMoves(int x, int y) override;
    virtual std::vector<std::string> getSpecificMoveStrings(Position currPosition, Board* gameBoard);
    virtual Character* clone();
};

#endif // BISHOP_HPP
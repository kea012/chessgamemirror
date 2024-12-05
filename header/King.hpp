#ifndef KING_HPP
#define KING_HPP

#include "../header/Character.hpp"

class King : public Character {
    public:
    King(std::string characterColor);
    //std::vector<std::string>* generatePossibleMoves(int x, int y) override;
    virtual std::vector<std::string> getSpecificMoveStrings(Position currPosition, Board* gameBoard);
    virtual Character* clone();
};

#endif // KING_HPP
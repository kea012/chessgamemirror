#ifndef KING_HPP
#define KING_HPP

#include "../header/Character.hpp"

class King : public Character {
    public:
    King(std::string characterColor);
    //std::vector<std::string>* generatePossibleMoves(int x, int y) override;
    virtual void updateMoves(Position currPosition, Board* gameBoard);
};

#endif // KING_HPP
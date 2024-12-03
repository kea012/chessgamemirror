#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "../header/Character.hpp"
#include "../header/QueenMove.hpp"

class Queen : public Character {
    public:
    Queen(std::string characterColor);
    //std::vector<std::string>* generatePossibleMoves(int x, int y) override;
    virtual void updateMoves(Position currPosition, Board* gameBoard);
};

#endif // QUEEN_HPP
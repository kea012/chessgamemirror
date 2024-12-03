#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "../header/Character.hpp"
#include "../header/BishopMove.hpp"

class Bishop : public Character {
  public:
    Bishop(std::string characterColor);
    //std::vector<std::string>* generatePossibleMoves(int x, int y) override;
    virtual void updateMoves(Position currPosition, Board* gameBoard);
};

#endif // BISHOP_HPP
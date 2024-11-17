#ifndef BISHOP_HPP
#define BISHOP_HPP

#include "Character.hpp"

class Bishop : public Character {
  public:
    Bishop(std::string Character_Color);
    std::vector<std::string>* generatePossibleMoves(int x, int y) override;
};

#endif // BISHOP_HPP
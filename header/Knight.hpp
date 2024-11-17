#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "Character.hpp"

class Knight : public Character {
  public:
    Knight(std::string Character_Color);
    std::vector<std::string>* generatePossibleMoves(int x, int y) override;
};

#endif // KNIGHT_HPP
#ifndef KNIGHT_HPP
#define KNIGHT_HPP

#include "../header/Character.hpp"

class Knight : public Character {
  public:
    Knight(std::string characterColor, std::string symbol);
    std::vector<std::string>* generatePossibleMoves(int x, int y) override;
};
 
#endif // KNIGHT_HPP 
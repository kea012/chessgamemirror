#ifndef PAWN_HPP
#define PAWN_HPP

#include "../header/Character.hpp"

class Pawn : public Character {
    public:
    Pawn(std::string characterColor, std::string symbol);
    std::vector<std::string>* generatePossibleMoves(int x, int y) override;
};

#endif // PAWN_HPP
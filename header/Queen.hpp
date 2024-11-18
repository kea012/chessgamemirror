#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "../header/Character.hpp"

class Queen : public Character {
    public:
    Queen(std::string characterColor);
    std::vector<std::string>* generatePossibleMoves(int x, int y) override;
};

#endif // QUEEN_HPP
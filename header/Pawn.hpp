#ifndef PAWN_HPP
#define PAWN_HPP

#include "../header/Character.hpp"

class Pawn : public Character {
    public:
    Pawn(std::string characterColor);
    void promotion();
};

#endif // PAWN_HPP
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "../header/Character.hpp"

class Pawn : public Character {
    Pawn(std::string characterColor);
    void promotion();
};

#endif // CHARACTER_HPP
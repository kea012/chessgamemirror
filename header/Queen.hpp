#ifndef QUEEN_HPP
#define QUEEN_HPP

#include "../header/Character.hpp"

class Queen : public Character {
    public:
    Queen(std::string characterColor);
    virtual std::vector<std::string> getSpecificMoveStrings(Position currPosition, Board* gameBoard);
    virtual Character* clone();
};

#endif // QUEEN_HPP
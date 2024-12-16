#ifndef PAWN_HPP
#define PAWN_HPP

#include "../header/Character.hpp"

class Pawn : public Character {
    private:
    int characterMoved = 0;
    public:
    Pawn(std::string characterColor);
    // int getMovedStatus() const;
    void setMoved();
    virtual std::vector<std::string> getSpecificMoveStrings(Position currPosition, Board* gameBoard);
    virtual Character* clone();
    int getMovedStatus() const override;
};

#endif // PAWN_HPP
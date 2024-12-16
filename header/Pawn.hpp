#ifndef PAWN_HPP
#define PAWN_HPP

#include "../header/Character.hpp"

class Pawn : public Character {
    private:
    bool characterMoved = false;
    public:
    Pawn(std::string characterColor);
    bool getMovedStatus() const;
    void setMoved();
    //std::vector<std::string>* generatePossibleMoves(int x, int y) override;
};

#endif // PAWN_HPP
#ifndef PAWN_HPP
#define PAWN_HPP

#include "../header/Character.hpp"

class Pawn : public Character {
    private:
    int characterMoved = 0;
    public:
    Pawn(std::string characterColor);
    int getMovedStatus() const;
    void setMoved();
    //std::vector<std::string>* generatePossibleMoves(int x, int y) override;
};

#endif // PAWN_HPP
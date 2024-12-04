#ifndef KING_HPP
#define KING_HPP

#include "../header/Character.hpp"

class King : public Character {
    private:
        int characterMoved = 0;
    public:
        King(std::string characterColor);
        int getMovedStatus() const;
        void setMoved();
    //std::vector<std::string>* generatePossibleMoves(int x, int y) override;
};

#endif // KING_HPP
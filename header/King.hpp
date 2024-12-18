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
        virtual std::vector<std::string> getSpecificMoveStrings(Position currPosition, Board* gameBoard);
        virtual Character* clone();
};

#endif // KING_HPP
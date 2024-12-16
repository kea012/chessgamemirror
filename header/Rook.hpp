#ifndef ROOK_HPP
#define ROOK_HPP

#include "../header/Character.hpp"

class Rook : public Character {
  private:
    int characterMoved = 0;
  public:
    Rook(std::string characterColor);
    int getMovedStatus() const;
    void setMoved();
    virtual std::vector<std::string> getSpecificMoveStrings(Position currPosition, Board* gameBoard);
    virtual Character* clone();
};

#endif // ROOK_HPP
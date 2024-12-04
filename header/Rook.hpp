#ifndef ROOK_HPP
#define ROOK_HPP

#include "../header/Character.hpp"
#include "../header/Position.hpp"

class Rook : public Character {
  private:
    int characterMoved = 0;
  public:
    Rook(std::string characterColor);
    int getMovedStatus() const;
    void setMoved();
    //std::vector<std::string>* generatePossibleMoves(int x, int y) override;
};

#endif // ROOK_HPP
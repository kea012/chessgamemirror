#ifndef ROOK_HPP
#define ROOK_HPP

#include "Character.hpp"
#include "Position.hpp"

class Rook : public Character {
  private:
    bool Character_Moved = false;
  public:
    Rook(std::string Character_Color);
    bool getMovedStatus() const;
    void setMoved();
    std::vector<std::string>* generatePossibleMoves(int x, int y) override;
};

#endif // ROOK_HPP
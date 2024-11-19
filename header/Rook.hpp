#ifndef ROOK_HPP
#define ROOK_HPP

#include "../header/Character.hpp"
#include "../header/Position.hpp"

class Rook : public Character {
  private:
    bool characterMoved = false;
  public:
    Rook(std::string characterColor, std::string symbol);
    bool getMovedStatus() const;
    void setMoved();
    std::vector<std::string>* generatePossibleMoves(int x, int y) override;
};

#endif // ROOK_HPP
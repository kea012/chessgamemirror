#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <vector>
#include "../header/Board.hpp"

enum CharacterType {PAWN, KING, KNIGHT, BISHOP, ROOK, QUEEN};

class Character {
  protected:
    bool alive = true;
    CharacterType type;
    std::string characterColor;
    std::string board[64];
  public:
    Character(CharacterType type, std::string characterColor);
    CharacterType getType() const;
    bool setAliveStatus();
    bool getAliveStatus() const;
    std::string getColor() const;
    virtual std::vector<std::string>* generatePossibleMoves(int x, int y);
};

#endif // CHARACTER_HPP
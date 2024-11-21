#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <vector>

enum CharacterType {PAWN, KING, KNIGHT, BISHOP, ROOK, QUEEN};

class Character {
  protected:
    bool alive = true;
    CharacterType type;
    std::string characterColor;
    std::string symbol;
  public: 
    Character(CharacterType type, std::string characterColor);
    CharacterType getType() const;
    bool setAliveStatus();
    bool getAliveStatus() const;
    std::string getColor() const;
    std::string getSymbol() const;
};

#endif // CHARACTER_HPP
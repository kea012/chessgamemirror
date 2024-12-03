#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <vector>
#include "../header/Position.hpp"
#include "../header/Board.hpp"

class Position;
class Board;

enum CharacterType {PAWN, KING, KNIGHT, BISHOP, ROOK, QUEEN};

class Character {
  protected:
    bool alive = true;
    CharacterType type;
    std::string characterColor;
    std::string symbol;
    std::vector<Position> moveList;
  public: 
    Character(CharacterType type, std::string characterColor);
    virtual ~Character() = default;
    CharacterType getType() const;
    bool setAliveStatus();
    bool getAliveStatus() const;
    std::string getColor() const;
    std::string getSymbol() const;
    std::vector<Position> getMoveList() const;
    virtual void updateMoves(Position currPosition, Board* gameBoard);
    void removeSelfCheckMoves(Position currPosition, Position newPosition, Board* gameBoard);
};

#endif // CHARACTER_HPP
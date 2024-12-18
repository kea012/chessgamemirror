#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>
#include <vector>
#include "../header/Position.hpp"

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
    virtual std::vector<std::string> getSpecificMoveStrings(Position currPosition, Board* gameBoard) = 0;
    virtual void updateMoves(Position currPosition, Board* gameBoard);
    void removeSelfCheckMoves(Position currPosition, Board* gameBoard);
    virtual Character* clone() = 0;
    virtual int getMovedStatus() const{return 0;}
};

#endif // CHARACTER_HPP
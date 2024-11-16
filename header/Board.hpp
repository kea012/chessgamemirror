#ifndef BOARD_HPP
#define BOARD_HPP

#include "../header/Position.hpp"
#include <string>

// INCOMPLETE VERSION OF CLASS FOR TESTING / FUNCTIONALITY OF GAME CLASS

class Board {
private:

public:
    Board();
    ~Board();
    bool isSpaceOccupied(Position pos);
    bool hasMoves(Position piecePos);
    bool isValidMovement(Position piecePos, Position movePos);
    std::string checkPieceColor(Position piecePos);
};

#endif
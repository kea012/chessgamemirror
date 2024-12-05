#ifndef KNIGHTMOVE_HPP
#define KNIGHTMOVE_HPP

#include "../header/Move.hpp"

class Board;

class KnightMove : public Move {
    private:
    Board* chessBoard;
    public:
    KnightMove(std::string color, Board* chessBoard);
    std::vector<std::string> generatePossibleMoves(int x, int y) override; 
};

#endif // KNIGHTMOVE_HPP
#ifndef PAWNMOVE_HPP
#define PAWNMOVE_HPP

#include "../header/Move.hpp"

class Board;

class PawnMove : public Move {
    private: 
    Board* chessBoard;
    public:
    PawnMove(std::string color, Board* chessBoard);
    virtual ~PawnMove() = default;
    std::vector<std::string> generatePossibleMoves(int x, int y) override; 
};

#endif // PAWNMOVE_HPP
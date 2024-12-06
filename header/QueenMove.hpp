#ifndef QUEENMOVE_HPP
#define QUEENMOVE_HPP

#include "../header/Move.hpp"

class Board;

class QueenMove : public Move {
    private: 
    Board* chessBoard;
    public:
    QueenMove(std::string color, Board* chessBoard);
    virtual ~QueenMove() = default;
    std::vector<std::string> generatePossibleMoves(int x, int y) override; 
};

#endif // QUEENMOVE_HPP
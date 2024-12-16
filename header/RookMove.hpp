#ifndef ROOKMOVE_HPP
#define ROOKMOVE_HPP

#include "../header/Move.hpp"

class Board;

class RookMove : public Move {
    private:
    Board* chessBoard;
    public:
    RookMove(std::string color, Board* chessBoard);
    virtual ~RookMove() = default; 
    std::vector<std::string> generatePossibleMoves(int x, int y) override; 
};

#endif // ROOKMOVE_HPP
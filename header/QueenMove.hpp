#ifndef QUEENMOVE_HPP
#define QUEENMOVE_HPP

#include "../header/Move.hpp"

class QueenMove : public Move {
    private: 
    Board* chessBoard;
    public:
    QueenMove(std::string color, Board* chessBoard);
    std::vector<std::string> generatePossibleMoves(int x, int y) override; 
};

#endif // QUEENMOVE_HPP
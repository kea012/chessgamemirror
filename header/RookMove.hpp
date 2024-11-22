#ifndef ROOKMOVE_HPP
#define ROOKMOVE_HPP

#include "../header/Move.hpp"

class RookMove : public Move {
    private:
    Board* chessBoard;
    public:
    RookMove(std::string color, Board* chessBoard);
    std::vector<std::string> generatePossibleMoves(int x, int y) override; 
};

#endif // QUEENMOVE_HPP
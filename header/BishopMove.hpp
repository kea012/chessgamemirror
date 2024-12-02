#ifndef BISHOPMOVE_HPP
#define BISHOPMOVE_HPP

#include "../header/Move.hpp"

class BishopMove : public Move {
    private:
    Board* chessBoard;
    public:
    BishopMove(std::string color, Board* chessBoard);
    std::vector<std::string> generatePossibleMoves(int x, int y) override; 
};

#endif // BISHOPMOVE_HPP
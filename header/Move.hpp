#ifndef MOVE_HPP
#define MOVE_HPP

#include <string>
#include <vector>

enum MoveType {PAWNMOVE, KINGMOVE, KNIGHTMOVE, BISHOPMOVE, ROOKMOVE, QUEENMOVE};

class Move {
    protected:
        MoveType type;
        std::string color;
        std::vector<std::string> possibleMoves;
    public:
        Move(MoveType type, std::string color);
        virtual std::vector<std::string> generatePossibleMoves(int x, int y) = 0;
        virtual ~Move() = default;
};

#endif // MOVE_HPP
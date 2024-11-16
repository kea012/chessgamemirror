#ifndef POSITION_HPP
#define POSITION_HPP

#include <string>

class Position {
private:
    int row;
    int col;
    std::string posStr;
public:
    Position();
    Position(int newRow, int newCol);
    Position(std::string posStr);
    void resetPosition();
    bool setPositionFromInts(int newRow, int newCol);
    bool setPositionFromString(std::string newPosStr);
    int getRow();
    int getCol();
    std::string getPositionString();
};

#endif
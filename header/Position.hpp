#ifndef POSITION_HPP
#define POSITION_HPP

#include <string>

class Position {
private:
    int row;
    int col;
    std::string positionString;
public:
    Position();
    Position(int newRow, int newCol);
    Position(std::string newPositionString);
    void resetPosition();
    bool setPositionFromInts(int newRow, int newCol);
    bool setPositionFromString(std::string newPositionString);
    bool isEmptyPosition();
    int getRow();
    int getCol();
    std::string getPositionString();
};

#endif
#include "../header/Position.hpp"

Position::Position() {
    resetPosition(); 
}

Position::Position(int newRow, int newCol) {
    if (!setPositionFromInts(newRow, newCol)) {
        resetPosition();
    }
}

Position::Position(std::string newPosStr) {
    if (!setPositionFromString(newPosStr)) {
        resetPosition();
    }
}

void Position::resetPosition() {
    row = -1;
    col = -1;
    posStr = "--";
}

bool Position::setPositionFromInts(int newRow, int newCol) {
    if (newRow < 0 || newRow > 7)
        return false;
    if (newCol < 0 || newCol > 7)
        return false;
    row = newRow;
    col = newCol;
    posStr[0] = row + 'A';
    posStr[1] = col + '1';
    return true;
}

bool Position::setPositionFromString(std::string newPosStr) {
    if (newPosStr.length() != 2)
        return false;
    switch(::toupper(newPosStr.front())) {
        case('A'):
        case('B'):
        case('C'):
        case('D'):
        case('E'):
        case('F'):
        case('G'):
        case('H'):
            break;
        default:
            return false;
    }
    switch(newPosStr.back()) {
        case('1'):
        case('2'):
        case('3'):
        case('4'):
        case('5'):
        case('6'):
        case('7'):
        case('8'):
            break;
        default:
            return false;
    }
    posStr = newPosStr;
    posStr[0] = ::toupper(posStr.front());

    return true;
}

bool Position::isEmptyPosition() {
    if (row == -1 || col == -1 || posStr == "--") {
        return true;
    }
    return false;
}

int Position::getRow() {
    return row;
}

int Position::getCol() {
    return col;
}

std::string Position::getPositionString() {
    return posStr;
}
#include "../header/Position.hpp"

Position::Position() {
    resetPosition(); 
}

Position::Position(int newRow, int newCol) {
    if (!setPositionFromInts(newRow, newCol)) {
        resetPosition();
    }
}

Position::Position(std::string newPositionString) {
    if (!setPositionFromString(newPositionString)) {
        resetPosition();
    }
}

void Position::resetPosition() {
    row = -1;
    col = -1;
    positionString = "--";
}

bool Position::setPositionFromInts(int newRow, int newCol) {
    if (newRow < 0 || newRow > 7)
        return false;
    if (newCol < 0 || newCol > 7)
        return false;
    row = newRow;
    col = newCol;
    positionString = "";
    positionString += (col + 'A');
    positionString += ('8' - row);
    return true;
}

bool Position::setPositionFromString(std::string newPositionString) {
    if (newPositionString.length() != 2)
        return false;
        
    char colChar = ::toupper(newPositionString.front());
    char rowChar = newPositionString.back();
    
    // Validate input
    if (colChar < 'A' || colChar > 'H' || rowChar < '1' || rowChar > '8') {
        return false;
    }
    
    // Convert chess notation to array indices
    col = colChar - 'A';  // A=0, B=1, etc.
    row = '8' - rowChar;  // 8=0, 7=1, etc. (flipped because chess notation starts from bottom)
    
    positionString = newPositionString;
    positionString[0] = colChar;  // Ensure uppercase
    
    return true;
}

bool Position::isEmptyPosition() {
    if (row == -1 || col == -1 || positionString == "--") {
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
    return positionString;
}

bool Position::operator==(Position const& rhs) const {
    return row == rhs.row && col == rhs.col;
}
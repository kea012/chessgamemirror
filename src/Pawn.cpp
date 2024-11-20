#include "../header/Pawn.hpp"

using namespace std;

Pawn::Pawn(string characterColor) : Character(PAWN, characterColor) {
    if (characterColor == "w") {
        symbol = "♟";
    }
    else if (characterColor == "b") {
        symbol = "♙";
    }
}

bool Pawn::getMovedStatus() const {
  return this->characterMoved;
}

void Pawn::setMoved() {
  this->characterMoved = true;
}

std::vector<std::string>* Pawn::generatePossibleMoves(int x, int y) {
   vector<string>* move = new vector<string>();
   /* //up the board
    for (int i = y + 1; i < 8; ++i) {
        if (board[x][i].is_empty()){
            move->push_back(to_string(x)+to_string(i)); // this move forward one space 
        }
        if (board[x][i].getMovedStatus() == true) { // breaks loop if it has already moved more than once
            break;
        }
        board[x][i].setMoved(); // if it hasnt moved yet its sets moved to true loop goes one more time then breaks.
    }
    
    //diagonol up and to the right of the board as well as en passant
    for (int i = x + 1, j = y + 1; (i < 8)&&(j < 8); ++i, ++j) {
        if ((board[i][j-1].getColor() != this->getColor()) && ((j-1) == 3)) {
            if(board[i][j-1].getMovedStatus() == true) {
                move->push_back(to_string(i)+to_string(j)); 
            }
        }
        if (board[i][j].is_empty()){
            break;
        }
        else if (board[i][j].getColor() != this->getColor()) {
            move->push_back(to_string(i)+to_string(j));
            break;
        }
        break;
    }

    //diagnol up and to the left of the board as well as en passant
    for (int i = x - 1, j = y + 1; (i >= 0)&&(j < 8); --i, ++j) {
        if ((board[i][j-1].getColor() != this->getColor()) && ((j-1) == 3)) {
            if(board[i][j-1].getMovedStatus() == true) {
                move->push_back(to_string(i)+to_string(j)); 
            }
        }
        if (board[i][j].is_empty()){
            break;
        }
        else if (board[i][j].getColor() != this->getColor()) {
            move->push_back(to_string(i)+to_string(j));
            break;
        }
        break;
    } */
     
    return move; 
}
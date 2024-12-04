#include "../header/Queen.hpp"

using namespace std;

Queen::Queen(string characterColor) : Character(QUEEN, characterColor) {
    if (characterColor == "w") {
        symbol = "♛";
    }
    else if (characterColor == "b") {
        symbol = "♕";
    }
}

/*std::vector<std::string>* Queen::generatePossibleMoves(int x, int y) {
    vector<string>* move = new vector<string>();
    //up the board
    for (int i = y + 1; i < 8; ++i) {
        if (chessBoard[x][i]->is_empty()){
            move->push_back(to_string(x)+to_string(i));
        }
        else if (chessBoard[x][i]->getColor() == this->getColor()) {
            break;
        }
        else {
            move->push_back(to_string(x)+to_string(i));
            break;
        }
    }

    //down the board
    for (int i = y - 1; (i >=0)&&(i < 8); --i) {
        if (chessBoard[x][i]->is_empty()){
            move->push_back(to_string(x)+to_string(i));
        }
        else if (chessBoard[x][i]->getColor() == this->getColor()) {
            break;
        }
        else {
            move->push_back(to_string(x)+to_string(i));
            break;
        }
    }

    //right side of the board
    for (int i = x + 1; i < 8; ++i) {
        if (chessBoard[i][y]->is_empty()){
            move->push_back(to_string(i)+to_string(y));
        }
        else if (chessBoard[i][y]->getColor() == this->getColor()) {
            break;
        }
        else {
            move->push_back(to_string(i)+to_string(y));
            break;
        }
    }

    //left side of the board;
    for (int i = x - 1; (i >= 0)&&(i < 8); --i) {
        if (chessBoard[i][y]->is_empty()){
            move->push_back(to_string(i)+to_string(y));
        }
        else if (chessBoard[i][y]->getColor() == this->getColor()) {
            break;
        }
        else {
            move->push_back(to_string(i)+to_string(y));
            break;
        }
    }

    //diagonol up and to the right of the board
    for (int i = x + 1, j = y + 1; (i < 8)&&(j < 8); ++i, ++j) {
        if (chessBoard[i][j]->is_empty()){
            move->push_back(to_string(i)+to_string(j));
        }
        else if (chessBoard[i][j]->getColor() == this->getColor()) {
            break;
        }
        else {
            move->push_back(to_string(i)+to_string(j));
            break;
        }
    }

    //diagnol up and to the left of the board
    for (int i = x - 1, j = y + 1; (i >= 0)&&(j < 8); --i, ++j) {
        if (chessBoard[i][j]->is_empty()){
            move->push_back(to_string(i)+to_string(j));
        }
        else if (chessBoard[i][j]->getColor() == this->getColor()) {
            break;
        }
        else {
            move->push_back(to_string(i)+to_string(j));
            break;
        }
    }

    //diagnol down and to the right of the board
    for (int i = x + 1, j = y - 1; (i < 8)&&(j >= 0); ++i, --j) {
        if (chessBoard[i][j]->is_empty()){
            move->push_back(to_string(i)+to_string(j));
        }
        else if (chessBoard[i][j]->getColor() == this->getColor()) {
            break;
        }
        else {
            move->push_back(to_string(i)+to_string(j));
            break;
        }
    }

    //diagnol down and to the left of the board
    for (int i = x - 1, j = y - 1; (i >= 0)&&(j >= 0); --i, --j) {
        if (chessBoard[i][j]->is_empty()){
            move->push_back(to_string(i)+to_string(j));
        }
        else if (chessBoard[i][j]->getColor() == this->getColor()) {
            break;
        }
        else {
            move->push_back(to_string(i)+to_string(j));
            break;
        }
    }
    
    return move;
}*/

void Queen::updateMoves(Position currPosition, Board* gameBoard) {
    moveList.clear();
    QueenMove moveGetter(characterColor, gameBoard);
    std::vector<std::string> moveStrings = moveGetter.generatePossibleMoves(currPosition.getRow(), currPosition.getCol());
    for (int i = 0; i < moveStrings.size(); i++) {
        moveList.push_back(Position(moveStrings.at(i)));
    }
}

Character* Queen::clone() {
    return new Queen(characterColor);
}
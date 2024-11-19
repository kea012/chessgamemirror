#include "../header/Queen.hpp"

using namespace std;

Queen::Queen(string characterColor, string symbol) : Character(QUEEN, characterColor, symbol) {}

std::vector<std::string>* Queen::generatePossibleMoves(int x, int y) {
    vector<string>* move = new vector<string>();
    //up the board
    /*for (int i = y + 1; i < 8; ++i) {
        if (board[x][i].is_empty()){
            move->push_back(to_string(x)+to_string(i));
        }
        else if (board[x][i].getColor() == this->getColor()) {
            break;
        }
        else {
            move->push_back(to_string(x)+to_string(i));
            break;
        }
    }

    //down the board
    for (int i = y - 1; (i >=0)&&(i < 8); --i) {
        if (board[x][i].is_empty()){
            move->push_back(to_string(x)+to_string(i));
        }
        else if (board[x][i].getColor() == this->getColor()) {
            break;
        }
        else {
            move->push_back(to_string(x)+to_string(i));
            break;
        }
    }

    //right side of the board
    for (int i = x + 1; i < 8; ++i) {
        if (board[i][y].is_empty()){
            move->push_back(to_string(i)+to_string(y));
        }
        else if (board[i][y].getColor() == this->getColor()) {
            break;
        }
        else {
            move->push_back(to_string(i)+to_string(y));
            break;
        }
    }

    //left side of the board;
    for (int i = x - 1; (i >= 0)&&(i < 8); --i) {
        if (board[i][y].is_empty()){
            move->push_back(to_string(i)+to_string(y));
        }
        else if (board[i][y].getColor() == this->getColor()) {
            break;
        }
        else {
            move->push_back(to_string(i)+to_string(y));
            break;
        }
    }

    //diagonol up and to the right of the board
    for (int i = x + 1, j = y + 1; (i < 8)&&(j < 8); ++i, ++j) {
        if (board[i][j].is_empty()){
            move->push_back(to_string(i)+to_string(j));
        }
        else if (board[i][j].getColor() == this->getColor()) {
            break;
        }
        else {
            move->push_back(to_string(i)+to_string(j));
            break;
        }
    }

    //diagnol up and to the left of the board
    for (int i = x - 1, j = y + 1; (i >= 0)&&(j < 8); --i, ++j) {
        if (board[i][j].is_empty()){
            move->push_back(to_string(i)+to_string(j));
        }
        else if (board[i][j].getColor() == this->getColor()) {
            break;
        }
        else {
            move->push_back(to_string(i)+to_string(j));
            break;
        }
    }

    //diagnol down and to the right of the board
    for (int i = x + 1, j = y - 1; (i < 8)&&(j >= 0); ++i, --j) {
        if (board[i][j].is_empty()){
            move->push_back(to_string(i)+to_string(j));
        }
        else if (board[i][j].getColor() == this->getColor()) {
            break;
        }
        else {
            move->push_back(to_string(i)+to_string(j));
            break;
        }
    }

    //diagnol down and to the left of the board
    for (int i = x - 1, j = y - 1; (i >= 0)&&(j >= 0); --i, --j) {
        if (board[i][j].is_empty()){
            move->push_back(to_string(i)+to_string(j));
        }
        else if (board[i][j].getColor() == this->getColor()) {
            break;
        }
        else {
            move->push_back(to_string(i)+to_string(j));
            break;
        }
    }*/
    
    return move;
}
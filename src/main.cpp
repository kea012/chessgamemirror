#include <iostream>
#include "../header/Board.hpp"
#include "../header/Move.hpp"
#include "../header/QueenMove.hpp"

using namespace std;

int main() {

    Board testBoard;
    string printBoard = testBoard.generateBoard();
    testBoard.printBoard(printBoard);

    Character* piece = testBoard.getPiece(4, 0);

    if (piece == nullptr) {
        cout << "null";
    }
    
    return 0;
}

 /*QueenMove newMove = QueenMove(testBoard->getPiece(4, 0)->getColor(), testBoard);
    //vector<string> moves = newMove.generatePossibleMoves(4, 0);

    for (int i = 0; i < moves.size(); ++i) {
        cout << moves.at(i);
    }*/
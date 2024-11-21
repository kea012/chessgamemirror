#include <iostream>
#include "../header/Board.hpp"
#include "../header/Move.hpp"
#include "../header/QueenMove.hpp"

using namespace std;

int main() {

    Board* testBoard = new Board();
    string printBoard = testBoard->generateBoard();
    testBoard->printBoard(printBoard);

    //remove pawn in front of queen
    if (testBoard->getPiece(1, 4)->getType() == 0) {
        testBoard->setPiece(1, 4, nullptr);
    }

    // try to get all the up moves for queen
    if (testBoard->getPiece(0, 4)->getType() == 5){
        QueenMove newMove = QueenMove(testBoard->getPiece(0, 4)->getColor(), testBoard);
        vector<string> moves = newMove.generatePossibleMoves(0, 4);
        for (int i = 0; i < moves.size(); ++i) {
            cout << moves.at(i) << endl;
        }
    }

    printBoard = testBoard->generateBoard();
    testBoard->printBoard(printBoard);

    delete testBoard;
    
    return 0;
}


#include <iostream>
#include "../header/Board.hpp"
#include "../header/Move.hpp"
#include "../header/QueenMove.hpp"

using namespace std;

int main() {

    Board testBoard;
    string printBoard = testBoard.generateBoard();
    testBoard.printBoard(printBoard);

    QueenMove newMove = QueenMove(testBoard.getPiece(4, 0)->getColor(), testBoard);
    vector<string> moves = newMove.generatePossibleMoves(4, 0);

    for (int i = 0; i < moves.size(); ++i) {
        cout << moves.at(i);
    }
    
    return 0;
}
#include "../header/Character.hpp"
#include "../header/Board.hpp"
#include "../header/Pawn.hpp"
#include "../header/Queen.hpp"
#include "../header/Bishop.hpp"
#include "../header/Knight.hpp"
#include "../header/Rook.hpp"
#include "../header/King.hpp"
#include "../header/Move.hpp"
#include "../header/QueenMove.hpp"
#include "gtest/gtest.h"
#include <string>

using namespace std;

TEST (Pawn, MakePawn) {

Pawn testPawn = Pawn("w");

EXPECT_EQ(testPawn.getType(), 0);
EXPECT_EQ(testPawn.getAliveStatus(), true);
EXPECT_EQ(testPawn.getColor(), "w");
EXPECT_EQ(testPawn.getSymbol(), "♟");
}

TEST (King, MakeKing) {

King testKing = King("w");

EXPECT_EQ(testKing.getType(), 1);
EXPECT_EQ(testKing.getAliveStatus(), true);
EXPECT_EQ(testKing.getColor(), "w");
EXPECT_EQ(testKing.getSymbol(), "♚");
}

TEST (Knight, MakeKnight) {

Knight testKnight = Knight("w");

EXPECT_EQ(testKnight.getType(), 2);
EXPECT_EQ(testKnight.getAliveStatus(), true);
EXPECT_EQ(testKnight.getColor(), "w");
EXPECT_EQ(testKnight.getSymbol(), "♞");
}

TEST (Bishop, MakeBishop) {

Bishop testBishop = Bishop("w");

EXPECT_EQ(testBishop.getType(), 3);
EXPECT_EQ(testBishop.getAliveStatus(), true);
EXPECT_EQ(testBishop.getColor(), "w");
EXPECT_EQ(testBishop.getSymbol(), "♝");
}

TEST (Rook, MakeRook) {

Rook testRook = Rook("w");

EXPECT_EQ(testRook.getType(), 4);
EXPECT_EQ(testRook.getAliveStatus(), true);
EXPECT_EQ(testRook.getColor(), "w");
EXPECT_EQ(testRook.getSymbol(), "♜");
}

TEST (Queen, MakeQueen) {

Queen testQueen = Queen("w");

EXPECT_EQ(testQueen.getType(), 5);
EXPECT_EQ(testQueen.getAliveStatus(), true);
EXPECT_EQ(testQueen.getColor(), "w");
EXPECT_EQ(testQueen.getSymbol(), "♛");
}

TEST (Board, MakeBoard) {
    EXPECT_NO_THROW(Board());
}

TEST (Board, PrintBoard) {
    Board* testBoard = new Board();
    string board = "1|♜||♞||♝||♚||♛||♝||♞||♜|\n2|♟||♟||♟||♟||♟||♟||♟||♟|\n3| || || || || || || || |\n4| || || || || || || || |\n5| || || || || || || || |\n6| || || || || || || || |\n7|♙||♙||♙||♙||♙||♙||♙||♙|\n8|♖||♘||♗||♕||♔||♗||♘||♖|\n  A  B  C  D  E  F  G  H";
    string printBoard = testBoard->generateBoard();
    EXPECT_EQ(printBoard, board);
}


TEST (QueenMove, MakeQueenMove) {
    Board* chessBoard = new Board();
    EXPECT_NO_THROW(QueenMove("w", chessBoard));
    delete chessBoard;
}

/*1|♜||♞||♝||♚||♛||♝||♞||♜|
2|♟||♟||♟||♟||♟||♟||♟||♟|
3| || || || || || || || |
4| || || || || || || || |
5| || || || || || || || |
6| || || || || || || || |
7|♙||♙||♙||♙||♙||♙||♙||♙|
8|♖||♘||♗||♕||♔||♗||♘||♖|
  A  B  C  D  E  F  G  H*/




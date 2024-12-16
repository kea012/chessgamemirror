#include "../header/Character.hpp"
#include "../header/Board.hpp"
#include "../header/Pawn.hpp"
#include "../header/PawnMove.hpp"
#include "../header/Queen.hpp"
#include "../header/QueenMove.hpp"
#include "../header/Bishop.hpp"
#include "../header/BishopMove.hpp"
#include "../header/Knight.hpp"
#include "../header/KnightMove.hpp"
#include "../header/Rook.hpp"
#include "../header/RookMove.hpp"
#include "../header/King.hpp"
#include "../header/KingMove.hpp"
#include "../header/Move.hpp"

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
    string board = "8|♜||♞||♝||♛||♚||♝||♞||♜|\n7|♟||♟||♟||♟||♟||♟||♟||♟|\n6| || || || || || || || |\n5| || || || || || || || |\n4| || || || || || || || |\n3| || || || || || || || |\n2|♙||♙||♙||♙||♙||♙||♙||♙|\n1|♖||♘||♗||♕||♔||♗||♘||♖|\n  A  B  C  D  E  F  G  H";
    string printBoard = testBoard->generateBoard();
    EXPECT_EQ(printBoard, board);
}

TEST(Board, getPiece){
    Board* chessBoard = new Board();
    Rook*  testRook = new Rook("w");
    EXPECT_EQ(chessBoard->getPiece(7,0)->getType(), testRook->getType());
    delete chessBoard;
}

TEST(Board, movePiece){
    Board* chessBoard = new Board();
    chessBoard->movePiece(6,0,5,0);
    Pawn* testPawn = new Pawn("w");
    EXPECT_EQ(chessBoard->getPiece(5,0)->getType(), testPawn->getType());
    delete chessBoard;
}

TEST(Board, TestIsSpaceOccupieForPosition00) {
    Board* chessBoard = new Board();
    EXPECT_FALSE(chessBoard->isSpaceOccupied("00"));
}

TEST(Board, TestIsSpaceOccupieForPosition75) {
    Board* chessBoard = new Board();
    EXPECT_FALSE(chessBoard->isSpaceOccupied("75"));
}

TEST (QueenMove, MakeQueenMove) {
    Board* chessBoard = new Board();
    EXPECT_NO_THROW(QueenMove("w", chessBoard));
    delete chessBoard;
}

TEST(QueenMove, TestQueenInitialPossibleMove) {
    Board* chessBoard = new Board();
    QueenMove queenMove("w", chessBoard);
    vector<string> moves = queenMove.generatePossibleMoves(0,3);
    EXPECT_EQ(moves.size(), 0);
    delete chessBoard;
}

TEST(QueenMove, TestQueenMoveAtRow4Column4) {
    Board* chessBoard = new Board();
    QueenMove queenMove("w", chessBoard);
    chessBoard->movePiece(0,3,3,3);
    vector<string> moves = queenMove.generatePossibleMoves(3,3);
    EXPECT_EQ(moves.size(), 19);
    delete chessBoard;
}

TEST(BishopMove, MakeBishopMove) {
    Board* chessBoard = new Board();
    EXPECT_NO_THROW(BishopMove("w", chessBoard));
    delete chessBoard;
}

TEST(BishopMove, TestBishopInitialPossibleMove) {
    Board* chessBoard = new Board();
    BishopMove bishopMove("w", chessBoard);
    vector<string> moves = bishopMove.generatePossibleMoves(0,2);
    EXPECT_EQ(moves.size(), 0);
    delete chessBoard;
}

TEST(BishopMove, TestBishopMoveAtRow4Column4) {
    Board* chessBoard = new Board();
    BishopMove bishopMove("w", chessBoard);
    chessBoard->movePiece(0,2,3,3);
    vector<string> moves = bishopMove.generatePossibleMoves(3,3);
    EXPECT_EQ(moves.size(), 8);
    delete chessBoard;
}

TEST(KingMove, MakeKingMove) {
    Board* chessBoard = new Board();
    EXPECT_NO_THROW(KingMove("w", chessBoard));
    delete chessBoard;
}

TEST(KingMove, TestKingInitialPossibleMove) {
    Board* chessBoard = new Board();
    KingMove kingMove("w", chessBoard);
    vector<string> moves = kingMove.generatePossibleMoves(0,4);
    EXPECT_EQ(moves.size(), 0);
    delete chessBoard;
}

TEST(KingMove, TestCastlingToLeft) {
    Board* chessBoard = new Board();
    KingMove kingMove("w", chessBoard);
    chessBoard->movePiece(0,1,2,2);
    chessBoard->movePiece(0,2,2,3);
    chessBoard->movePiece(0,3,2,4);
    vector<string> moves = kingMove.generatePossibleMoves(0,4);
    EXPECT_EQ(moves.size(), 2); // should have 03, 02
    
    string target = "02"; // castling move
    bool found = false;
    for (int i = 0; i < moves.size(); ++i) {
        if (moves[i] == target)
            found = true;
    }
    EXPECT_TRUE(found);
    delete chessBoard;
}

TEST(KingMove, TestCastlingToRight) {
    Board* chessBoard = new Board();
    KingMove kingMove("w", chessBoard);
    chessBoard->movePiece(0,5,2,4);
    chessBoard->movePiece(0,6,2,5);
    vector<string> moves = kingMove.generatePossibleMoves(0,4);
    EXPECT_EQ(moves.size(), 2); // should have 05, 06
    
    string target = "06"; // castling move
    bool found = false;
    for (int i = 0; i < moves.size(); ++i) {
        if (moves[i] == target)
            found = true;
    }
    EXPECT_TRUE(found);
    delete chessBoard;
}

TEST(KingMove, TestCastlingIfMoved) {
    Board* chessBoard = new Board();
    KingMove kingMove("w", chessBoard);
    chessBoard->movePiece(0,5,2,4);
    chessBoard->movePiece(0,6,2,5);
    static_cast<King*>(chessBoard->getPiece(0,4))->setMoved();
    vector<string> moves = kingMove.generatePossibleMoves(0,4);
    EXPECT_EQ(moves.size(), 1); // should have 05
    
    string target = "06"; // castling move
    bool found = false;
    for (int i = 0; i < moves.size(); ++i) {
        if (moves[i] == target)
            found = true;
    }
    EXPECT_FALSE(found);
    delete chessBoard;
}

TEST(KnightMove, MakeKnightMove) {
    Board* chessBoard = new Board();
    EXPECT_NO_THROW(KnightMove("w", chessBoard));
    delete chessBoard;
}

TEST(KnightMove, TestKnightInitialPossibleMove) {
    Board* chessBoard = new Board();
    KnightMove knightMove("w", chessBoard);
    vector<string> moves = knightMove.generatePossibleMoves(0,1);
    EXPECT_EQ(moves.size(), 2);

    string target = "20"; // left
    bool found = false;
    for (int i = 0; i < moves.size(); ++i) {
        if (moves[i] == target)
            found = true;
    }
    EXPECT_TRUE(found);
    target = "22"; // right
    found = false;
    for (int i = 0; i < moves.size(); ++i) {
        if (moves[i] == target)
            found = true;
    }
    EXPECT_TRUE(found);
    delete chessBoard;
}

TEST(RookMove, MakeRookMove) {
    Board* chessBoard = new Board();
    EXPECT_NO_THROW(RookMove("w", chessBoard));
    delete chessBoard;
}

TEST(RookMove, TestRookInitialPossibleMove) {
    Board* chessBoard = new Board();
    RookMove rookMove("w", chessBoard);
    vector<string> moves = rookMove.generatePossibleMoves(0,0);
    EXPECT_EQ(moves.size(), 0);
    delete chessBoard;
}

TEST(RookMove, TestRookMovesAtRow4Column1) {
    Board* chessBoard = new Board();
    RookMove rookMove("w", chessBoard);
    chessBoard->movePiece(0,0,3,0);
    vector<string> moves = rookMove.generatePossibleMoves(3,0);
    EXPECT_EQ(moves.size(), 11);
    delete chessBoard;
}

TEST(PawnMove, MakePawnMove) {
    Board* chessBoard = new Board();
    EXPECT_NO_THROW(PawnMove("w", chessBoard));
    delete chessBoard;
}

TEST(PawnMove, TestRookInitialPossibleMove) {
    Board* chessBoard = new Board();
    PawnMove pawnMove("w", chessBoard);
    vector<string> moves = pawnMove.generatePossibleMoves(1,3);
    EXPECT_EQ(moves.size(), 2);
    delete chessBoard;
}

TEST(PawnMove, TestRookMoveAtRow6Column4) {
    Board* chessBoard = new Board();
    PawnMove pawnMove("w", chessBoard);
    chessBoard->movePiece(0,0,5,3);
    vector<string> moves = pawnMove.generatePossibleMoves(5,3);
    EXPECT_EQ(moves.size(), 2);
    
    string target = "64"; // right
    bool found = false;
    for (int i = 0; i < moves.size(); ++i) {
        if (moves[i] == target)
            found = true;
    }
        EXPECT_TRUE(found);

    target = "62"; // left
    found = false;
    for (int i = 0; i < moves.size(); ++i) {
        if (moves[i] == target)
            found = true;
    }
        EXPECT_TRUE(found);
    delete chessBoard;
}
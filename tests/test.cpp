#include "../header/Character.hpp"
#include "../header/Board.hpp"
#include "../header/Pawn.hpp"
#include "../header/Queen.hpp"
#include "../header/Bishop.hpp"
#include "../header/Knight.hpp"
#include "../header/Rook.hpp"
#include "../header/King.hpp"
#include "gtest/gtest.h"

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




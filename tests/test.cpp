#include "../header/Character.hpp"
#include "../header/Pawn.hpp"
#include "../header/Queen.hpp"
#include "gtest/gtest.h"

TEST (Pawn, MakePawn) {

Pawn testPawn = Pawn("w");

EXPECT_EQ(testPawn.getType(), 0);
EXPECT_EQ(testPawn.getAliveStatus(), true);
EXPECT_EQ(testPawn.getColor(), "w");
}

TEST (Queen, MakeQueen) {

Queen testQueen = Queen("w");

EXPECT_EQ(testQueen.getType(), 5);
EXPECT_EQ(testQueen.getAliveStatus(), true);
EXPECT_EQ(testQueen.getColor(), "w");
}

TEST (Bishop, MakeBishop) {

Bishop testBishop = Bishop("w");

EXPECT_EQ(testBishop.getType(), 5);
EXPECT_EQ(testBishop.getAliveStatus(), true);
EXPECT_EQ(testBishop.getColor(), "w");
}
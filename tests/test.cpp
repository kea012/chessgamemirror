#include "../header/Character.hpp"
#include "../header/Pawn.hpp"
#include "gtest/gtest.h"

TEST (Pawn, MakePawn) {

Pawn testPawn = Pawn("w");

EXPECT_EQ(testChar.getType(), 0);
EXPECT_EQ(testChar.getAliveStatus(), true);
EXPECT_EQ(testChar.getColor(), "w");
}
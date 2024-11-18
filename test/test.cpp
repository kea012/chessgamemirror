#include "../header/Character.hpp"
#include "../header/Board.hpp"
#include "gtest/gtest.h"


TEST (Character, Make Character) {

Board* newBoard = new Board();

Character testChar = Character(PAWN, "w", newBoard);

EXPECT_EQ(testChar.getType(), 0);
EXPECT_EQ(testChar.getAliveStatus(), true);
EXPECT_EQ(testChar.getColor(), true);
}
#include "../header/Character.hpp"
#include "gtest/gtest.h"


TEST (Character, MakeCharacter) {

string board[0]

Character testChar = Character(PAWN, "w", board);

EXPECT_EQ(testChar.getType(), 0);
EXPECT_EQ(testChar.getAliveStatus(), true);
EXPECT_EQ(testChar.getColor(), true);
}
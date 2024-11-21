#include "gtest/gtest.h"
#include "../header/Game.hpp"

TEST(GameConstructorTests, DefaultOutputString) {
    Game tGame;
    std::string tStr = "WELCOME TO CHESS\nEnter 'S' to start a new game or 'Q' to quit the program";

    EXPECT_EQ(tGame.getOutputString(), tStr);
}

TEST(GameConstructorTests, DefaultTurnState) {
    Game tGame;

    EXPECT_EQ(tGame.getTurn(), noTurn);
}

TEST(GameConstructorTests, DefaultPiecePos) {
    Game tGame;
    Position tPiecePos = tGame.getSelectedPiecePos();

    int tRow = tPiecePos.getRow();
    int tCol = tPiecePos.getCol();
    std::string tPosStr = tPiecePos.getPositionString();

    EXPECT_EQ(tRow, -1);
    EXPECT_EQ(tCol, -1);
    EXPECT_EQ(tPosStr, "--");
}

TEST(GameConstructorTests, DefaultMovePos) {
    Game tGame;
    Position tMovePos = tGame.getSelectedMovePos();

    int tRow = tMovePos.getRow();
    int tCol = tMovePos.getCol();
    std::string tPosStr = tMovePos.getPositionString();

    EXPECT_EQ(tRow, -1);
    EXPECT_EQ(tCol, -1);
    EXPECT_EQ(tPosStr, "--");
}

TEST(GameConstructorTests, DefaultBoard) {
    Game tGame;
    Board* tBoard = tGame.getGameBoard();

    EXPECT_EQ(tBoard, nullptr);
}

TEST(UpdateTurnTests, whiteToBlackToWhite) {
    Game tGame;

    EXPECT_TRUE(tGame.updateTurn());
    EXPECT_EQ(tGame.getTurn(), whiteTurn);

    EXPECT_TRUE(tGame.updateTurn());
    EXPECT_EQ(tGame.getTurn(), blackTurn);

    EXPECT_TRUE(tGame.updateTurn());
    EXPECT_EQ(tGame.getTurn(), whiteTurn);
}

TEST(UpdateTurnTests, whiteToNoTurn) {
    Game tGame;

    EXPECT_TRUE(tGame.updateTurn());
    EXPECT_EQ(tGame.getTurn(), whiteTurn);

    EXPECT_TRUE(tGame.updateTurn(true));
    EXPECT_EQ(tGame.getTurn(), noTurn);
}

TEST(UpdateTurnTests, blackToNoTurn) {
    Game tGame;

    EXPECT_TRUE(tGame.updateTurn());
    EXPECT_EQ(tGame.getTurn(), whiteTurn);

    EXPECT_TRUE(tGame.updateTurn());
    EXPECT_EQ(tGame.getTurn(), blackTurn);

    EXPECT_TRUE(tGame.updateTurn(true));
    EXPECT_EQ(tGame.getTurn(), noTurn);
}

TEST(UpdateTurnTests, noUpdate) {
    Game tGame;

    EXPECT_EQ(tGame.getTurn(), noTurn);
    EXPECT_TRUE(!tGame.updateTurn());
    EXPECT_EQ(tGame.getTurn(), noTurn);
}
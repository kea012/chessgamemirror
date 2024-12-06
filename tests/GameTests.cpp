#include "gtest/gtest.h"
#include "../header/Game.hpp"
#include "../header/GameAction.hpp"
#include "../header/GameState.hpp"

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
    EXPECT_TRUE(!tGame.updateTurn(true));
    EXPECT_EQ(tGame.getTurn(), noTurn);
}

TEST(StateToActionTests, MenuScreenToCreateGame) {
    Game tGame;
    std::string expectedStr = "Starting new game...\nWhite player's turn\nEnter 'M' to make a move or 'Q' to quit game";
    std::string tInput1 = "S";
    std::string tInput2 = "s";

    tGame.updateGameState(new MenuScreen());
    tGame.inputToAction(tInput1);
    tGame.performCurrAction();
    std::string tStr1 = tGame.getOutputString();
    EXPECT_EQ(tStr1, expectedStr);

    tGame.updateGameState(new MenuScreen());
    tGame.inputToAction(tInput2);
    tGame.performCurrAction();
    std::string tStr2 = tGame.getOutputString();
    EXPECT_EQ(tStr2, expectedStr);
}

TEST(StateToActionTests, MenuScreenToEndProgram) {
    Game tGame;
    std::string expectedStr = "Ending program...";
    std::string tInput1 = "Q";
    std::string tInput2 = "q";

    tGame.updateGameState(new MenuScreen());
    tGame.inputToAction(tInput1);
    tGame.performCurrAction();
    std::string tStr1 = tGame.getOutputString();
    EXPECT_EQ(tStr1, expectedStr);

    tGame.updateGameState(new MenuScreen());
    tGame.inputToAction(tInput2);
    tGame.performCurrAction();
    std::string tStr2 = tGame.getOutputString();
    EXPECT_EQ(tStr2, expectedStr);
}

TEST(StateToActionTests, MenuScreenToInvalidInput) {
    Game tGame;
    std::string expectedStr = "Invalid input";
    std::string tInput1 = "p";
    std::string tInput2 = "E3";

    tGame.updateGameState(new MenuScreen());
    tGame.inputToAction(tInput1);
    tGame.performCurrAction();
    std::string tStr1 = tGame.getOutputString();
    EXPECT_EQ(tStr1, expectedStr);

    tGame.updateGameState(new MenuScreen());
    tGame.inputToAction(tInput2);
    tGame.performCurrAction();
    std::string tStr2 = tGame.getOutputString();
    EXPECT_EQ(tStr2, expectedStr);
}

TEST(StateToActionTests, EndScreenToCreateGame) {
    Game tGame;
    std::string expectedStr = "Starting new game...\nWhite player's turn\nEnter 'M' to make a move or 'Q' to quit game";
    std::string tInput1 = "S";
    std::string tInput2 = "s";

    tGame.updateGameState(new EndScreen());
    tGame.inputToAction(tInput1);
    tGame.performCurrAction();
    std::string tStr1 = tGame.getOutputString();
    EXPECT_EQ(tStr1, expectedStr);

    tGame.updateGameState(new EndScreen());
    tGame.inputToAction(tInput2);
    tGame.performCurrAction();
    std::string tStr2 = tGame.getOutputString();
    EXPECT_EQ(tStr2, expectedStr);
}

TEST(StateToActionTests, EndScreenToReturnToMenu) {
    Game tGame;
    std::string expectedStr = "WELCOME TO CHESS\nEnter 'S' to start a new game or 'Q' to quit the program";
    std::string tInput1 = "Q";
    std::string tInput2 = "q";

    tGame.updateGameState(new EndScreen());
    tGame.inputToAction(tInput1);
    tGame.performCurrAction();
    std::string tStr1 = tGame.getOutputString();
    EXPECT_EQ(tStr1, expectedStr);

    tGame.updateGameState(new EndScreen());
    tGame.inputToAction(tInput2);
    tGame.performCurrAction();
    std::string tStr2 = tGame.getOutputString();
    EXPECT_EQ(tStr2, expectedStr);
}

TEST(StateToActionTests, EndScreenToInvalidInput) {
    Game tGame;
    std::string expectedStr = "Invalid input";
    std::string tInput1 = "x";
    std::string tInput2 = "za2Al";

    tGame.updateGameState(new EndScreen());
    tGame.inputToAction(tInput1);
    tGame.performCurrAction();
    std::string tStr1 = tGame.getOutputString();
    EXPECT_EQ(tStr1, expectedStr);

    tGame.updateGameState(new EndScreen());
    tGame.inputToAction(tInput2);
    tGame.performCurrAction();
    std::string tStr2 = tGame.getOutputString();
    EXPECT_EQ(tStr2, expectedStr); 
}

TEST(StateToActionTests, TurnStartToSelectPiece) {
    Game tGame;
    std::string expectedStr = "Enter a position to select a piece";
    std::string tInput1 = "M";
    std::string tInput2 = "m";

    tGame.updateGameState(new TurnStart());
    tGame.inputToAction(tInput1);
    tGame.performCurrAction();
    std::string tStr1 = tGame.getOutputString();
    EXPECT_EQ(tStr1, expectedStr);

    tGame.updateGameState(new TurnStart());
    tGame.inputToAction(tInput2);
    tGame.performCurrAction();
    std::string tStr2 = tGame.getOutputString();
    EXPECT_EQ(tStr2, expectedStr); 
}

// Will need to update once check for winner is implemented
TEST(StateToActionTests, TurnStartToRetire) {
    Game tGame;
    std::string expectedStr = "Player who didn't retire won the game\nEnter 'S' to start a new game or 'Q' to return to the menu";
    std::string tInput1 = "Q";
    std::string tInput2 = "q";

    tGame.updateGameState(new TurnStart());
    tGame.inputToAction(tInput1);
    tGame.performCurrAction();
    std::string tStr1 = tGame.getOutputString();
    EXPECT_EQ(tStr1, expectedStr);

    tGame.updateGameState(new TurnStart());
    tGame.inputToAction(tInput2);
    tGame.performCurrAction();
    std::string tStr2 = tGame.getOutputString();
    EXPECT_EQ(tStr2, expectedStr); 
}

TEST(StateToActionTests, TurnStartToInvalidInput) {
    Game tGame;
    std::string expectedStr = "Invalid input";
    std::string tInput1 = "S";
    std::string tInput2 = "D7";

    tGame.updateGameState(new TurnStart());
    tGame.inputToAction(tInput1);
    tGame.performCurrAction();
    std::string tStr1 = tGame.getOutputString();
    EXPECT_EQ(tStr1, expectedStr);

    tGame.updateGameState(new TurnStart());
    tGame.inputToAction(tInput2);
    tGame.performCurrAction();
    std::string tStr2 = tGame.getOutputString();
    EXPECT_EQ(tStr2, expectedStr); 
}

// Will need to update tests once CheckPiece is implemented with Board checks
TEST(StateToActionTests, SelectingPieceToCheckPiece) {
    Game tGame;
    std::string expectedStr = "Enter a position to move selected piece to or 'R' to select a different piece";
    std::string tInput1 = "A3";
    std::string tInput2 = "H8";

    tGame.updateGameState(new SelectingPiece());
    tGame.inputToAction(tInput1);
    tGame.performCurrAction();
    std::string tStr1 = tGame.getOutputString();
    EXPECT_EQ(tStr1, expectedStr);

    tGame.updateGameState(new SelectingPiece());
    tGame.inputToAction(tInput2);
    tGame.performCurrAction();
    std::string tStr2 = tGame.getOutputString();
    EXPECT_EQ(tStr2, expectedStr); 
}

TEST(StateToActionTests, SelectingPieceToInvalidInput) {
    Game tGame;
    std::string expectedStr = "Invalid input";
    std::string tInput1 = "A0";
    std::string tInput2 = "D9";

    tGame.updateGameState(new SelectingPiece());
    tGame.inputToAction(tInput1);
    tGame.performCurrAction();
    std::string tStr1 = tGame.getOutputString();
    EXPECT_EQ(tStr1, expectedStr);

    tGame.updateGameState(new SelectingPiece());
    tGame.inputToAction(tInput2);
    tGame.performCurrAction();
    std::string tStr2 = tGame.getOutputString();
    EXPECT_EQ(tStr2, expectedStr); 
}

TEST(StateToActionTests, SelectingMoveToSelectPiece) {
    Game tGame;
    std::string expectedStr = "Enter a position to select a piece";
    std::string tInput1 = "R";
    std::string tInput2 = "r";

    tGame.updateGameState(new SelectingMove());
    tGame.inputToAction(tInput1);
    tGame.performCurrAction();
    std::string tStr1 = tGame.getOutputString();
    EXPECT_EQ(tStr1, expectedStr);

    tGame.updateGameState(new SelectingMove());
    tGame.inputToAction(tInput2);
    tGame.performCurrAction();
    std::string tStr2 = tGame.getOutputString();
    EXPECT_EQ(tStr2, expectedStr); 
}

// Will need to update tests once CheckMove is implemented with Board checks
TEST(StateToActionTests, SelectingMoveToCheckMove) {
    Game tGame;
    std::string expectedStr = "Enter 'C' to confirm movement or 'R' to select a different position";
    std::string tInput1 = "A6";
    std::string tInput2 = "F4";

    tGame.updateGameState(new SelectingMove());
    tGame.inputToAction(tInput1);
    tGame.performCurrAction();
    std::string tStr1 = tGame.getOutputString();
    EXPECT_EQ(tStr1, expectedStr);

    tGame.updateGameState(new SelectingMove());
    tGame.inputToAction(tInput2);
    tGame.performCurrAction();
    std::string tStr2 = tGame.getOutputString();
    EXPECT_EQ(tStr2, expectedStr); 
}

TEST(StateToActionTests, SelectingMoveToInvalidInput) {
    Game tGame;
    std::string expectedStr = "Invalid input";
    std::string tInput1 = "A0";
    std::string tInput2 = "D9";

    tGame.updateGameState(new SelectingMove());
    tGame.inputToAction(tInput1);
    tGame.performCurrAction();
    std::string tStr1 = tGame.getOutputString();
    EXPECT_EQ(tStr1, expectedStr);

    tGame.updateGameState(new SelectingMove());
    tGame.inputToAction(tInput2);
    tGame.performCurrAction();
    std::string tStr2 = tGame.getOutputString();
    EXPECT_EQ(tStr2, expectedStr); 
}

/* Relies heavily on Board implementation, will need to have a valid piece and valid move selected
TEST(StateToActionTests, ConfirmingMoveToMovePiece) {

}
*/

TEST(StateToActionTests, ConfirmingMoveToSelectMove) {
    Game tGame;
    std::string expectedStr = "Enter a position to move selected piece to";
    std::string tInput1 = "R";
    std::string tInput2 = "r";

    tGame.updateGameState(new ConfirmingMove());
    tGame.inputToAction(tInput1);
    tGame.performCurrAction();
    std::string tStr1 = tGame.getOutputString();
    EXPECT_EQ(tStr1, expectedStr);

    tGame.updateGameState(new ConfirmingMove());
    tGame.inputToAction(tInput2);
    tGame.performCurrAction();
    std::string tStr2 = tGame.getOutputString();
    EXPECT_EQ(tStr2, expectedStr); 
}
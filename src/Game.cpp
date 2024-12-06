#include "../header/Character.hpp" 
#include "../header/Game.hpp"
#include "../header/Board.hpp"
#include "../header/Character.hpp"
#include "../header/GameState.hpp"
#include "../header/GameAction.hpp"

Game::Game() {
    currGameState = new MenuScreen();
    currTurn = noTurn;
    outputString = "WELCOME TO CHESS\nEnter 'S' to start a new game or 'Q' to quit the program";
}

Game::~Game() {
    if (gameBoard != nullptr)
        delete gameBoard;
    if (currGameState != nullptr)
        delete currGameState;
    if (currAction != nullptr)
        delete currAction;
}

Board* Game::getGameBoard() {
    return gameBoard;
}

turn Game::getTurn() {
    return currTurn;
}

Position Game::getSelectedPiecePos() {
    return piecePos;
}

Position Game::getSelectedMovePos() {
    return movePos;
}

std::string Game::getOutputString() {
    return outputString;
}

GameState* Game::getGameState() {
    return currGameState;
}

bool Game::createNewBoard() {
    if (gameBoard != nullptr)
        return false;
    gameBoard = new Board();
    return true;
}

bool Game::setBoard(Board* newGameBoard) {
    if (gameBoard != nullptr)
        return false;
    gameBoard = newGameBoard;
    return true;
}

void Game::updateGameState(GameState* newGameState) {
    delete currGameState;
    currGameState = newGameState;
}

bool Game::updateTurn(bool gameEnding) {
    if (gameEnding) {
        if (currTurn == noTurn)
            return false;
        else
            currTurn = noTurn;
    }
    else {
        switch(currTurn) {
            case(noTurn):
                currTurn = whiteTurn;
                break;
            case(whiteTurn):
                currTurn = blackTurn;
                break;
            case(blackTurn):
                currTurn = whiteTurn;
        }
    }
    return true;
}

bool Game::updatePiecePosition(std::string newPosStr) {
    return piecePos.setPositionFromString(newPosStr);
}

bool Game::updateMovePosition(std::string newPosStr) {
    return movePos.setPositionFromString(newPosStr);
}

void Game::resetPositions() {
    piecePos.resetPosition();
    movePos.resetPosition();
}

void Game::resetWholeGame() {
    resetPositions();
    updateTurn(true);
    delete gameBoard;
    gameBoard = nullptr;
    delete currAction;
    currAction = nullptr;
}

bool Game::inputToAction(std::string userInput) {
    if (!currGameState)
        return false;
    currAction = currGameState->parseUserInput(userInput);
    return true;
}

bool Game::performCurrAction() {
    if (!currAction)
        return false;
    outputString = currAction->performAction(this);
    return true;
}

bool Game::moveSelectedPiece() {
    return gameBoard->movePiece(piecePos.getRow(), piecePos.getCol(), movePos.getRow(), movePos.getCol());
}

bool Game::getNewMoves(std::string color) {
    if (color != "b" && color != "w") {
        return false;
    }
    gameBoard->generateAllPlayerMoves();
    gameBoard->removeAllSelfCheckMoves(color);
    return true;
}
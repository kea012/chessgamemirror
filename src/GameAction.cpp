#include "../header/GameAction.hpp"
#include "../header/Game.hpp"
#include "../header/GameState.hpp"
#include "../header/Board.hpp"
#include "../header/Character.hpp"

// InvalidInput functions

std::string InvalidInput::performAction(Game* activeGame) {
    return "Invalid input";
}

// CreateGame functions

std::string CreateGame::performAction(Game* activeGame) {
    // Will likely eventually write a specific function to check that certain expected preconditions are met
    // (e.g. gameBoard object exists, currTurn is white or black) and reset Game members if not met
    
    if (!activeGame->createNewBoard()) {
        activeGame->updateGameState(new MenuScreen);
        activeGame->resetWholeGame();
        return "CRITICAL ERROR: Reseting...\nWELCOME TO CHESS\nEnter 'S' to start a new game or 'Q' to quit the program";
    }
    
    activeGame->updateGameState(new TurnStart);
    activeGame->updateTurn();
    activeGame->getGameBoard()->generateAllPlayerMoves("w");
    std::string newOutputString = "Starting new game...\n";
    newOutputString += activeGame->getGameBoard()->generateBoard() + "\n";
    newOutputString += "White player's turn\nEnter 'M' to make a move or 'Q' to quit game";
    return newOutputString;
}

// EndProgram functions

std::string EndProgram::performAction(Game* activeGame) {
    activeGame->updateGameState(nullptr);
    return "Ending program...";
}

// SelectPiece functions

std::string SelectPiece::performAction(Game* activeGame) {
    activeGame->updateGameState(new SelectingPiece);
    return "Enter a position to select a piece";
}

// CheckPiece functions

CheckPiece::CheckPiece(Position newPiecePos) {
    piecePos.setPositionFromString(newPiecePos.getPositionString());
}

std::string CheckPiece::performAction(Game* activeGame) {
    
    Character* tempCharacter = activeGame->getGameBoard()->getPiece(piecePos.getRow(), piecePos.getCol());
    turn currTurn = activeGame->getTurn();
    // Case where selected position does not contain one of the current player's pieces
    if (tempCharacter == nullptr || (currTurn == whiteTurn && tempCharacter->getColor() == "b")
        || (currTurn == blackTurn && tempCharacter->getColor() == "w")) {
        activeGame->updateGameState(new SelectingPiece);
        tempCharacter = nullptr;
        return "Selected position does not contain one of your pieces\nEnter a position to select a piece";
    }
    // Case where selected position contains current player's piece but piece has no legal moves
    if (false) {
        activeGame->updateGameState(new SelectingPiece);
        tempCharacter = nullptr;
        return "Selected piece has no legal moves\nEnter a position to select a different piece";
    }
    tempCharacter = nullptr;
    
    activeGame->updatePiecePosition(piecePos.getPositionString());
    activeGame->updateGameState(new SelectingMove);
    return "Enter a position to move selected piece to or 'R' to select a different piece";
}

// SelectMove functions

std::string SelectMove::performAction(Game* activeGame) {
    activeGame->updateGameState(new SelectingMove);
    return "Enter a position to move selected piece to";
}

// CheckMove functions

CheckMove::CheckMove(Position newMovePos) {
    movePos.setPositionFromString(newMovePos.getPositionString());
}

std::string CheckMove::performAction(Game* activeGame) {
    Position currentPos = activeGame->getSelectedPiecePos();
    std::string currentColor = activeGame->getGameBoard()->checkPieceColor(currentPos);
    std::string targetColor = activeGame->getGameBoard()->checkPieceColor(movePos);
    
    if (!targetColor.empty() && targetColor == currentColor) { // User selected position that selected piece cannot move to
        activeGame->updateGameState(new SelectingMove);
        return "Select a valid position";
    }
    activeGame->updateMovePosition(movePos.getPositionString());
    activeGame->updateGameState(new ConfirmingMove);
    return "Enter 'C' to confirm movement or 'R' to select a different position";
}

// MovePiece functions

std::string MovePiece::performAction(Game* activeGame) {
    activeGame->moveSelectedPiece();
    std::string initialPos = activeGame->getSelectedPiecePos().getPositionString();
    std::string finalPos = activeGame->getSelectedMovePos().getPositionString();
    activeGame->resetPositions();
    std::string newOutputString = "Moved piece from " + initialPos + " to " + finalPos + "\n";
    newOutputString += activeGame->getGameBoard()->generateBoard() + "\n";

    std::string nextTurnColor;
    if (activeGame->getTurn() == blackTurn) {
        nextTurnColor == "w";
    }
    else if (activeGame->getTurn() == whiteTurn) {
        nextTurnColor == "b";
    }
    activeGame->getGameBoard()->generateAllPlayerMoves(nextTurnColor);

    if (!activeGame->getGameBoard()->colorHasMoves(nextTurnColor)) {
        if (activeGame->getGameBoard()->isKingInCheck(nextTurnColor)) {
            if (activeGame->getTurn() == blackTurn) {
                newOutputString += "\nBlack has won the game!";
            }
            else if (activeGame->getTurn() == whiteTurn)  {
                newOutputString += "\nWhite has won the game!";
            }
        }
        else {
            newOutputString += "\nThe game ended in a draw";
        }
        activeGame->updateGameState(new EndScreen);
        activeGame->resetWholeGame();
        newOutputString += "\nEnter 'S' to start a new game or 'Q' to return to the menu";
        return newOutputString;
    }
    activeGame->updateTurn();
    activeGame->updateGameState(new TurnStart);
    if (activeGame->getTurn() == whiteTurn) {
        newOutputString += "\nWhite player's turn";
    }
    else if (activeGame->getTurn() == blackTurn) {
        newOutputString += "\nBlack player's turn";
    }
    newOutputString += "\nEnter 'M' to make a move or 'Q' to quit";
    return newOutputString;
}

// Retire functions

std::string Retire::performAction(Game* activeGame) {
    std::string newOutputString;
    if (activeGame->getTurn() == whiteTurn) {
        newOutputString = "White has retired, so black has won the game";
    }
    else if (activeGame->getTurn() == blackTurn) {
        newOutputString = "Black has retired, so white has won the game";
    }
    activeGame->updateGameState(new EndScreen);
    activeGame->resetWholeGame();
    newOutputString += "\nEnter 'S' to start a new game or 'Q' to return to the menu";
    return newOutputString;
}

// ReturnToMenu functions

std::string ReturnToMenu::performAction(Game* activeGame) {
    activeGame->updateGameState(new MenuScreen);
    return "WELCOME TO CHESS\nEnter 'S' to start a new game or 'Q' to quit the program";
}
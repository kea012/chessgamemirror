#include "../header/GameAction.hpp"

// InvalidInput functions

std::string InvalidInput::performAction(Game* activeGame) {
    return "Invalid input";
}

// CreateGame functions

std::string CreateGame::performAction(Game* activeGame) {
    activeGame->updateGameState(new TurnStart);
    activeGame->updateTurn();
    return "Starting new game...\nWhite player's turn\nEnter 'M' to make a move or 'Q' to quit game";
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
    if (false) { // User selected position that does not contain piece that they can move / will have to check current turn / could have different return strings
        activeGame->updateGameState(new SelectingPiece);
        return "Select a valid position";
    }
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
    if (false) { // User selected position that selected piece cannot move to
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
    std::string str = "Moved piece from " + initialPos + " to " + finalPos;
    if (false) { // Check for any game ending conditions
        activeGame->updateGameState(new EndScreen);
        if (false) { // Someone won
            str += "\nSomeone won the game";
        }
        else { // Draw
            str += "\nThe game ended in a draw";
        }
        activeGame->updateTurn(true);
        str += "\nEnter 'S' to start a new game or 'Q' to return to the menu";
        return str;
    }
    activeGame->updateTurn();
    activeGame->updateGameState(new TurnStart);
    if (activeGame->getTurn() == whiteTurn) {
        str += "\nWhite player's turn";
    }
    else if (activeGame->getTurn() == blackTurn) {
        str += "\nBlack player's turn";
    }
    str += "\nEnter 'M' to make a move or 'Q' to quit";
    return str;
}

// Retire functions

std::string Retire::performAction(Game* activeGame) {
    activeGame->updateGameState(new EndScreen);
    std::string str = "Player who didn't retire won the game"; // will check current player's turn
    activeGame->updateTurn(true);
    str += "\nEnter 'S' to start a new game or 'Q' to return to the menu";
    return str;
}

// ReturnToMenu functions

std::string ReturnToMenu::performAction(Game* activeGame) {
    activeGame->updateGameState(new MenuScreen);
    return "WELCOME TO CHESS\nEnter 'S' to start a new game or 'Q' to quit the program";
}
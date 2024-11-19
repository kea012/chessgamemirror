#include "../header/Board.hpp"

//Sets up the piece color vectors and sets up pieces on the board
//all indices without pieces are set to nullptr - check if that works in a character pointer class
//tests: check that the pieces are placed properly
//make sure that the piece vectors are set up correctly
Board::Board(){
    // Pawn WP1(w), WP2(w), WP3(w), WP4(w), WP5(w), WP6(w), WP7(w), WP8(w);
    // Pawn BP1, BP2, BP3, BP4, BP5, BP6, BP7, BP8;
    // Rook WR1, WR2, BR1, BR2;
    // King BK, WK;
    // Queen BQ, WQ;
    // Bishop BB1, BB2, WB1, WB2;
    // Knight BN1, BN2, WN1, WN2;
    //whitePiece(0) = WP1;
    int row = 0;
    int column = 0;

    //Push back all white pieces into white piece vector Z
    whitePieces.push_back(new Rook("w"));
    whitePieces.push_back(new Knight("w"));
    whitePieces.push_back(new Bishop("w"));
    whitePieces.push_back(new Queen("w"));
    whitePieces.push_back(new Bishop("w"));
    whitePieces.push_back(new Knight("w"));
    whitePieces.push_back(new Rook("w"));
    for (unsigned int i = 0; i < 7; i++){
        whitePieces.push_back(new Pawn("w"));
    }
    blackPieces.push_back(new Rook("w"));
    blackPieces.push_back(new Knight("w"));
    blackPieces.push_back(new Bishop("w"));
    blackPieces.push_back(new Queen("w"));
    blackPieces.push_back(new Bishop("w"));
    blackPieces.push_back(new Knight("w"));
    blackPieces.push_back(new Rook("w"));
    for (unsigned int i = 0; i < 7; i++){
        blackPieces.push_back(new Pawn("w"));
    }

    row = 0;
    column = 0;
    //set back pieces first then pawns for white
    for (unsigned int i = 0; i < 15; ++i){
        chessBoard[row][column] = whitePieces.at(i);
        column++;
        if (column == 8){
            row++;
            column = 0;
        }
    }
    row = 7;
    column = 0;
    for (unsigned int i = 0; i < 15; ++i){
        chessBoard[row][column] = blackPieces.at(i);
        column++;
        if (column == 8){
            row--;
            column = 0;
        }
    }

    row = 2;
    column = 0;
    for (unsigned int i = 0; i < 32; ++i){
        chessBoard[row][column] = nullptr;
        column++;
        if (column == 8){
            row++;
            column = 0;
        }
    }
}

bool Board::isSpaceOccupied(std::string position) {
     char column = position.at(0) - '0';
     char row = position.at(1) - '0';
    if (chessBoard[column][row] == nullptr){
        return true;
    }
    return false;
}

bool Board::isSpaceOccupied(Position pos) {
    // Complete function will check if there is a Character at pos
    return false;
}

bool hasMoves(Position piecePos) {
    // Complete function will check if the Character at piecePos has available moves
    return false;
}

bool isValidMovement(Position piecePos, Position movePos) {
    // Complete function will check if the position in movePos exists in the list of possible moves of the Character at piecePos
    return false;
}

std::string checkPieceColor(Position piecePos) {
    // Complete function will return color of the Character at piecePos
    return "black";
}


Character* Board::addPiece(){
    return nullptr;
}

void Board::movePiece(){

}

void Board::capturePiece(){

}

bool Board::stalemate(){
    return false;
}

string Board::generateBoard(){
    string board = "";
    for (unsigned int row = 0; row < 8; ++row){
        for (unsigned int column = 0; column < 8; ++column){
            board += "|";
            board += chessBoard[row][column]->getSymbol();
            board += "|  ";
        }
        board += "\n";
        board += to_string(row);
        board + "  ";
    }
    board += "A   B   C   D   E   F   G   H";
    return board;
}

void Board::printBoard(string boardString){
    cout << boardString;
}


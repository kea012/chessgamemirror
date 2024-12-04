#ifndef _BOARD_H_
#define _BOARD_H_

#include "../header/Character.hpp"
#include "../header/Pawn.hpp"
#include "../header/King.hpp"
#include "../header/Knight.hpp"
#include "../header/Bishop.hpp"
#include "../header/Rook.hpp"
#include "../header/Queen.hpp"
#include "../header/Position.hpp"

#include <string>
#include <vector>

class Character;

class Board {
	protected:
		Character* chessBoard[8][8] = {nullptr}; 
	private:
		std::vector<Character*> whitePieces;
		std::vector<Character*> blackPieces;
	public:
		Board();
		Board(const Board& rhs);
		Board& operator=(const Board& rhs);
		~Board();
		bool isSpaceOccupied(std::string position);
		bool isSpaceOccupied(Position pos);
		bool hasMoves(Position piecePos);
		bool isValidMovement(Position piecePos, Position movePos);
		std::string checkPieceColor(Position piecePos);
		std::string generateBoard();
		void capturePiece();
		bool stalemate();
		void printBoard(std::string boardString);
		Character* getPiece(int row, int column) const;
		void setPiece(int row, int column, Character* insertChar);
		void movePiece(int initialRow, int initialColumn, int newRow, int newColumn);
		void pawnPromotion(int row, int column, std::string type);
		bool removePieceFromList(Character* pieceToRemove);
		bool generateAllPlayerMoves(std::string color);
		bool removeAllSelfCheckMoves(std::string color);
		Position getKingPosition(std::string color);
		bool isKingInCheck(std::string color);
		void clearBoard();
};

#endif

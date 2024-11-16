#ifndef _BOARD_H_
#define _BOARD_H_

class board {
	private:
		Character* chessBoard = Character[8][8];
		vector<Character*> whitePieces;
		vector<character*> blackPieces;
	public:
		bool isSpaceOccupied();
		Character* addPiece();
		void movePiece();
		void capturePiece();
		bool stalemate();
		void printBoard();
}

#endif

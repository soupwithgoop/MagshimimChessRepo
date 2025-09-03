#pragma once

#include "Piece.h"

#define BOARD_SIZE 8
#define START_STRING "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR0"

using namespace std;

class Player;
class Piece;

class Board
{
public:
	Board(Player* white, Player* black);
	~Board();
	void print() const;
	void getString(char res[]) const;
	bool isPieceOfPlayer(int row, int col, Player* pl) const;
	bool tryMove(int srcRow, int srcCol, int dstRow, int dstCol) const;
	Team getTeam(int row, int col) const;
	void Move(int srcRow, int srcCol, int dstRow, int dstCol) ;
	void undoLastMove();

private:
	Piece* createPiece(char sign, int row, int column, Player* white, Player* black);
	void fixPosition(int row, int column);

	Piece* _brd[BOARD_SIZE][BOARD_SIZE];

	int _lastSrcRow;
	int _lastSrcCol;
	int _lastDstRow;
	int _lastDstCol;
	Piece* _lastPiece;
};
#pragma once

#include "Player.h"

using namespace std;

class Player;
class Board;


class Piece
{
public:
	char getSign() const;
	Player* getPlayer() const;
	virtual bool isLegalMove(int, int) const = 0;
	void setPosition(int row, int col);
	Piece(Player*, char sign, int row, int col, Board* board);
	virtual ~Piece();
	int getRow() const;
	int getColumn() const;

private:
	char _sign;

protected:
	Player* _player; // not reference because can be null

	int _startRow;
	int _startCol;
	int _row;
	int _col;
	Board* _brd;

	bool isWayFree(int dstRow, int dstCol) const;
};
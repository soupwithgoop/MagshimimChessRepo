#pragma once

#include "Piece.h"

#define QUEEN_SIGN 'q'


class Queen : public Piece
{
public:
	Queen(Player* p, int row, int col, Board* brd);
	virtual bool isLegalMove(int, int) const;

private:

};
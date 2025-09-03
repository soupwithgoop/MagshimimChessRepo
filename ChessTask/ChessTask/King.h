#pragma once

#include "Piece.h"

#define KING_SIGN 'k'


class King : public Piece
{
public:
	King(Player* p, int row, int col, Board* brd);
	virtual bool isLegalMove(int, int) const;

private:

};
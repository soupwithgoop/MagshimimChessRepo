#pragma once

#include "Piece.h"

#define ROOK_SIGN 'r'


class Rook : public Piece
{
public:
	Rook(Player* p, int row, int col, Board* brd);
	virtual bool isLegalMove(int, int) const;

private:

};
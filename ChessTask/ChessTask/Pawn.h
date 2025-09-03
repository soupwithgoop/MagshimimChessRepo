#pragma once

#include "Piece.h"

#define PAWN_SIGN 'p'


class Pawn : public Piece
{
public:
	Pawn(Player* p, int row, int col, Board* brd);

	virtual bool isLegalMove(int, int) const;
private:
};
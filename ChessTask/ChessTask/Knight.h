#pragma once

#include "Piece.h"

#define KNIGHT_SIGN 'n'


class Knight : public Piece
{
public:
	Knight(Player* p , int row, int col, Board* brd);
	virtual bool isLegalMove(int, int) const;

private:

};
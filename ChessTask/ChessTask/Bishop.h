#pragma once

#include "Piece.h"

#define BISHOP_SIGN 'b'


class Bishop : public Piece
{
public:
	Bishop(Player* p , int row, int col, Board*);
	virtual bool isLegalMove(int, int) const;

private:

};
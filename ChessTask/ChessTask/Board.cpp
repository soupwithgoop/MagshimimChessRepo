#pragma once

#include "Board.h"
#include "NullPiece.h"
#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"
#include <string>
#include <cctype>
Board::Board(Player* white, Player* black)
{
	for (int row = 0; row < BOARD_SIZE; ++row)
		for (int column = 0; column < BOARD_SIZE; ++column)
			_brd[row][column] = nullptr;
	_lastSrcRow = _lastSrcCol = _lastDstRow = _lastDstCol = -1;
	_lastPiece = nullptr;


	for (int row = 0; row < BOARD_SIZE; row++)
	{
		for (int column = 0; column < BOARD_SIZE; column++)
		{
			int index = column + (row * BOARD_SIZE);
			_brd[row][column] = createPiece(START_STRING[index], row, column, white, black);
		}
	}

}

Board::~Board()
{
}

Piece* Board::createPiece(char sign, int row, int column, Player* white, Player* black)
{
	Piece* newPiece = nullptr;
	if (sign == NULLPIECE_SIGN) 
	{
		newPiece = new NullPiece(row, column);
		return newPiece;
	}
	Player* player = (sign >= 'A' && sign <= 'Z') ? white : black;

	switch (tolower(sign))
	{
		case PAWN_SIGN:
			newPiece = new Pawn(player, row, column, this);
			break;
		case ROOK_SIGN:
			newPiece = new Rook(player, row, column, this);
			break;
		case BISHOP_SIGN:
			newPiece = new Bishop(player, row, column, this);
			break;
		case KNIGHT_SIGN:
			newPiece = new Knight(player, row, column, this);
			break;
		case QUEEN_SIGN:
			newPiece = new Queen(player, row, column, this);
			break;
		case KING_SIGN:
			King* king = new King(player, row, column, this);
			player->setKing(king);
			newPiece = king;
			break;
	}
	player->addPiece(newPiece);
	return newPiece;
}

void Board::fixPosition(int row, int column)
{
	_brd[row][column]->setPosition(row, column);
}

void Board::print() const
{
}

void Board::getString(char res[]) const
{
	for (int row = 0; row < BOARD_SIZE; row++)
	{
		for (int column = 0; column < BOARD_SIZE; column++) 
		{
			int index = column + (row * BOARD_SIZE);
			res[index] = _brd[row][column]->getSign();
		}
	}
}

bool Board::isPieceOfPlayer(int row, int col, Player* pl) const
{
	Team teamThis = _brd[row][col]->getPlayer() ? _brd[row][col]->getPlayer()->getTeam() : NONE;
	Team teamPlayer = pl ? pl->getTeam() : NONE;
	return teamThis == teamPlayer;
}

bool Board::tryMove(int srcRow, int srcCol, int dstRow, int dstCol) const
{
	return _brd[srcRow][srcCol]->isLegalMove(dstRow, dstCol);
}

Team Board::getTeam(int row, int col) const
{	
	return _brd[row][col]->getPlayer() ? _brd[row][col]->getPlayer()->getTeam() : NONE;
}

void Board::Move(int srcRow, int srcCol, int dstRow, int dstCol)
{
	if (_lastPiece != nullptr)
		delete _lastPiece;

	_lastSrcRow = srcRow;
	_lastSrcCol = srcCol;
	_lastDstRow = dstRow;
	_lastDstCol = dstCol;
	_lastPiece = _brd[dstRow][dstCol];

	_brd[dstRow][dstCol] = _brd[srcRow][srcCol];
	fixPosition(dstRow, dstCol);
	_brd[srcRow][srcCol] = new NullPiece(srcRow, srcCol);
	if (_lastPiece->getPlayer() != nullptr) {
		_lastPiece->getPlayer()->removePiece(_lastPiece);
	}
}

void Board::undoLastMove()
{
	delete _brd[_lastSrcRow][_lastSrcCol];

	_brd[_lastSrcRow][_lastSrcCol] = _brd[_lastDstRow][_lastDstCol];
	fixPosition(_lastSrcRow, _lastSrcCol);
	_brd[_lastDstRow][_lastDstCol] = _lastPiece;

	_lastSrcRow = _lastSrcCol = _lastDstRow = _lastDstCol = -1;
	if (_lastPiece->getPlayer() != nullptr)
		_lastPiece->getPlayer()->addPiece(_lastPiece);
	_lastPiece = nullptr;
}

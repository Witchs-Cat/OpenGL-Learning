#include "CursorData.h"

void CursorData::MoveTo(POINT& cursorPosition)
{
	_move.x = cursorPosition.x - _currentPosition.x;
	_move.y = cursorPosition.y - _currentPosition.y;

	_currentPosition.x = cursorPosition.x;
	_currentPosition.y = cursorPosition.y;
}

POINT* CursorData::GetPosition()
{
	return &_currentPosition;
}

POINT* CursorData::GetMove()
{
	return &_move;
}
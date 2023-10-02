#include "UpdateEventArgs.h"

UpdateEventArgs::UpdateEventArgs(double elapsed, POINT* cursorPosition, POINT* cursorMove) :
	BaseEventArgs(elapsed)
{
	_CursorPosition = cursorPosition;
	_CursorMove = cursorMove;
}

bool UpdateEventArgs::KeyIsPressed(int keyId)
{
	return GetKeyState(keyId) & 0x8000;
}

POINT* UpdateEventArgs::GetCursorPosition()
{
	return _CursorPosition;
}

POINT* UpdateEventArgs::GetCursorMove()
{
	return _CursorMove;
}

UpdateEventArgs::~UpdateEventArgs()
{
	delete _CursorMove;
	delete _CursorPosition;
}

#include "UpdateEventArgs.h"


bool UpdateEventArgs::KeyIsPressed(int keyId)
{
	return GetKeyState(keyId) & 0x8000;
}

CursorData* UpdateEventArgs::GetCursorData()
{
	return &_cursorData;
}

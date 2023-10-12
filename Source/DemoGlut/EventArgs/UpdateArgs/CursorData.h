#pragma once
#include "..\BaseEventArgs.h"

class CursorData
{
private:
	POINT _move;
	POINT _currentPosition;
public:

	void MoveTo(POINT& cursorPoision);
	POINT* GetPosition();
	POINT* GetMove();

};


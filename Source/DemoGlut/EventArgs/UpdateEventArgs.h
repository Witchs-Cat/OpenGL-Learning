#pragma once
#include "BaseEventArgs.h"

class UpdateEventArgs : 
	public BaseEventArgs
{
private:
	POINT* _CursorMove;
	POINT* _CursorPosition;
public:
	UpdateEventArgs(double elapsed, POINT* cursorPosition, POINT* cursorMove);
	bool KeyIsPressed(int keyId);
	POINT* GetCursorPosition();
	POINT* GetCursorMove();
	
	~UpdateEventArgs();
};


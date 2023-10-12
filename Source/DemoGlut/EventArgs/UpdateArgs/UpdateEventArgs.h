#pragma once
#include "CursorData.h"

class UpdateEventArgs : 
	public BaseEventArgs
{
private:
	CursorData _cursorData;
public:
	bool KeyIsPressed(int keyId);
	CursorData* GetCursorData();
};


#include "EventsFactory.h"
#include <iostream>

using namespace std::chrono;

EventsFactory::EventsFactory()
{
	_lastCursorPosition = new POINT;
}

POINT* GetCurrentCursorPosition()
{
	POINT position;
	if (GetCursorPos(&position)) 
	{
		POINT* result = new POINT;
		result->x = position.x;
		result->y = position.y;
		return result;
	}
	return nullptr;
}

//Снова утечка
void EventsFactory::GetEventArgs(UpdateEventArgs*& updateArgs, RenderEventArgs*& renderArgs)
{
	auto now = std::chrono::system_clock::now();

	long long elapsedNanoseconds = duration_cast<nanoseconds>(now - _lastRenderingTime).count();
	double elapsedMilliseconds = elapsedNanoseconds / 10E5;

	_lastRenderingTime = now;

	auto cursorMove = new POINT();
	POINT* cursorPosition = GetCurrentCursorPosition();

	if (cursorPosition == nullptr)
		cursorPosition = _lastCursorPosition;

	cursorMove->x = _lastCursorPosition->x - cursorPosition->x;
	cursorMove->y = _lastCursorPosition->y - cursorPosition->y;
	_lastCursorPosition->x = cursorPosition->x;
	_lastCursorPosition->y = cursorPosition->y;

	updateArgs = new UpdateEventArgs(elapsedMilliseconds, cursorPosition, cursorMove);
	renderArgs = new RenderEventArgs(elapsedMilliseconds);
}


void EventsFactory::UpdateState()
{
	_lastRenderingTime = std::chrono::system_clock::now();

	POINT* cursorPosition = GetCurrentCursorPosition();
	if (cursorPosition != nullptr)
	{
		_lastCursorPosition->x = cursorPosition->x;
		_lastCursorPosition->y = cursorPosition->y;
	}
	delete cursorPosition;
}

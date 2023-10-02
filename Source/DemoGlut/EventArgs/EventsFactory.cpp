#include "EventsFactory.h"
#include <iostream>

using namespace std::chrono;

EventsFactory::EventsFactory()
{
	_lastCursorPosition = new POINT;
}

void EventsFactory::GetEventArgs(UpdateEventArgs*& updateArgs, RenderEventArgs*& renderArgs)
{
	auto now = std::chrono::system_clock::now();

	long long elapsedNanoseconds = duration_cast<nanoseconds>(now - _lastRenderingTime).count();
	double elapsedMilliseconds = elapsedNanoseconds / 10E5;

	_lastRenderingTime = now;
	updateArgs = new UpdateEventArgs(elapsedMilliseconds, new POINT, new POINT);
	renderArgs = new RenderEventArgs(elapsedMilliseconds);
}

void EventsFactory::UpdateState()
{
	_lastRenderingTime = std::chrono::system_clock::now();

	LPPOINT position{};
	if (GetCursorPos(position))
	{
		_lastCursorPosition->x = position->x;
		_lastCursorPosition->y = position->y;
	}
	else
	{
		_lastCursorPosition->x = -1;
		_lastCursorPosition->y = -1;
	}
}

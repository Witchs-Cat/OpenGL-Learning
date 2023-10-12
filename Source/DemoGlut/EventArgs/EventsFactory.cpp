#include "EventsFactory.h"
#include <iostream>

using namespace std::chrono;

EventsFactory::EventsFactory()
{
	_updateArgs = new UpdateEventArgs();
	_renderArgs = new RenderEventArgs();
}

UpdateEventArgs* EventsFactory::GetUpdateArgs()
{
	return _updateArgs;
}


RenderEventArgs* EventsFactory::GetRenderArgs()
{
	return _renderArgs;
}

void EventsFactory::UpdateState()
{
	auto now = std::chrono::system_clock::now();

	long long elapsedMicroseconds = (now.time_since_epoch() - _lastRenderingTime.time_since_epoch()).count();
	double elapsedMilliseconds = elapsedMicroseconds / 10E3;

	_lastRenderingTime = now;

	auto cursorMove = new POINT();

	POINT cursorPosition;
	if (GetCursorPos(&cursorPosition))
	{
		_updateArgs->GetCursorData()->MoveTo(cursorPosition);
	}

	_updateArgs->SetElapsedMilliseconds(elapsedMilliseconds);
	_renderArgs->SetElapsedMilliseconds(elapsedMilliseconds);
}

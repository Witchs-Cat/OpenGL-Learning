#include "EventsFactory.h"

void EventsFactory::GetEventArgs(UpdateEventArgs*& updateArgs, RenderEventArgs*& renderArgs)
{
	auto now = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed = now - _lastRenderingTime;

	_lastRenderingTime = now;
	updateArgs = new UpdateEventArgs(elapsed.count());
	renderArgs = new RenderEventArgs(elapsed.count());
}

void UpdateLastRenderingTime()
{
	_lastRenderingTime = std::chrono::system_clock::now();
}
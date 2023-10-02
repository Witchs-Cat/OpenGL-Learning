#pragma once

#include "UpdateEventArgs.h"
#include "RenderEventArgs.h"

class EventsFactory
{
private:
	std::chrono::system_clock::time_point _lastRenderingTime;	
public:
	void GetEventArgs(UpdateEventArgs*& updateArgs, RenderEventArgs*& renderArgs);
	void UpdateLastRenderingTime();
};


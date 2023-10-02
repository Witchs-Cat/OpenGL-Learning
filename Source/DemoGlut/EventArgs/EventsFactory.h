#pragma once

#include "UpdateEventArgs.h"
#include "RenderEventArgs.h"

class EventsFactory
{
private:
	std::chrono::system_clock::time_point _lastRenderingTime;
	POINT* _lastCursorPosition;
public:
	EventsFactory();
	//ТУТ ВНИМАНИЕ
	//По задумке аргументы событий не живут дольше 1 цикла
	//Наверное лучше использовать умные указатели
	void GetEventArgs(UpdateEventArgs*& updateArgs, RenderEventArgs*& renderArgs);
	void UpdateState();
};


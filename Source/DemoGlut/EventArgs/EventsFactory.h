#pragma once

#include ".\RenderArgs\RenderEventArgs.h"
#include ".\UpdateArgs\UpdateEventArgs.h"

class EventsFactory
{
private:
	std::chrono::system_clock::time_point _lastRenderingTime;
	//POINT* _lastCursorPosition;
	UpdateEventArgs* _updateArgs;
	RenderEventArgs* _renderArgs;
public:
	EventsFactory();
	//ТУТ ВНИМАНИЕ
	//По задумке аргументы событий живут в течении всего времени работы программы
	//Наверное лучше использовать умные указатели
	void GetEventArgs(UpdateEventArgs*& updateArgs, RenderEventArgs*& renderArgs);
	UpdateEventArgs* GetUpdateArgs();
	RenderEventArgs* GetRenderArgs();
	void UpdateState();
};


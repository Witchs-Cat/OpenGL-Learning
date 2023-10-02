#pragma once

#include "../Includes.h"

//ТУТ ВНИМАНИЕ
//По задумке аргументы событий не живут дольше 1 цикла
class BaseEventArgs abstract
{
private:
	double _elapsedMilliseconds;
public:
	BaseEventArgs(double elapsedMilliseconds);
	double GetElapsedMilliseconds();
};


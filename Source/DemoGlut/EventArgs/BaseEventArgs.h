#pragma once

#include "../Includes.h"

class BaseEventArgs abstract
{
private:
	double _elapsedMilliseconds;
public:
	BaseEventArgs(double elapsedMilliseconds);
	double GetElapsedMilliseconds();
};


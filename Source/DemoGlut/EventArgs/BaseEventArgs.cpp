#include "BaseEventArgs.h"

double BaseEventArgs::GetElapsedMilliseconds()
{
	return _elapsedMilliseconds;
}

void BaseEventArgs::SetElapsedMilliseconds(double elapsedMilliseconds)
{
	_elapsedMilliseconds = elapsedMilliseconds;
}
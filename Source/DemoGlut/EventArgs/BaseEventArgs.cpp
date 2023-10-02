#include "BaseEventArgs.h"

BaseEventArgs::BaseEventArgs(double elapsed)
{
	_elapsedMilliseconds = elapsed;
}

double BaseEventArgs::GetElapsedMilliseconds()
{
	return _elapsedMilliseconds;
}

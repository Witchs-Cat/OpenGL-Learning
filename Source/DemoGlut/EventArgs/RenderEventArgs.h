#pragma once
#include "BaseEventArgs.h"
class RenderEventArgs :
	public BaseEventArgs
{
public:
	RenderEventArgs(double elapsed);
};


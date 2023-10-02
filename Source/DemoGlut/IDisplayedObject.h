#pragma once

#include "Includes.h"

#include "EventArgs/UpdateEventArgs.h"
#include "EventArgs/RenderEventArgs.h"

class IDisplayedObject abstract
{
	void virtual Render(RenderEventArgs* args) abstract;
	void virtual Update(UpdateEventArgs* args) abstract;
};


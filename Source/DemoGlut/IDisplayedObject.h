#pragma once

#include "Includes.h"

#include "EventArgs/EventsFactory.h"

class IDisplayedObject abstract
{
	void virtual Render(RenderEventArgs* args) abstract;
	void virtual Update(UpdateEventArgs* args) abstract;
};


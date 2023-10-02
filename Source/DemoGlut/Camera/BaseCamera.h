#pragma once

#include "..\IDisplayedObject.h"

class BaseCamera : IDisplayedObject
{
public:
	void virtual Render(RenderEventArgs* args);
	void virtual Update(UpdateEventArgs* args);
};


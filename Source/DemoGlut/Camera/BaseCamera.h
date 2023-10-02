#pragma once

#include "..\IDisplayedObject.h"

class BaseCamera : IDisplayedObject
{
protected:
	double _cameraX;
	double _cameraY;
	double _cameraZ;
	
	double _targetX;
	double _targetY;
	double _targetZ;

	double _upX;
	double _upY;
	double _upZ;

public:
	void virtual Render(RenderEventArgs* args);
	void virtual Update(UpdateEventArgs* args);

	void SetCameraPosition(double x, double y, double z);
	void SetTargetPosition(double x, double y, double z);
	void SetUpVector(double x, double y, double z);
};

